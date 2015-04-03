
#include "nkro.h"
#include "hid-report-generator.h"
#include "layers.h"
#include <stdint.h>

#define NumReports (2)

inputReport_t reportBuffer[NumReports];
static uint8_t currentReport;
static uint32_t activeLayers;
static uint32_t oldMatrices[4] = {0, 0, 0, 0};
static enum KeyNum_t making[4 * 32] = { [0] = KB_Transparent, };

void initReportGernerator ( void ) {
  int reportCounter, byteCounter;
  for( reportCounter = 0; reportCounter < NumReports; ++reportCounter )
    for( byteCounter = 0; byteCounter < BytesPerReport; ++byteCounter )
      ( ( uint8_t *) &reportBuffer[ reportCounter ])[ byteCounter ] = 0;
  activeLayers = 1;
  currentReport = 0; }

enum KeyNum_t ScanCodeToKeyNum ( uint32_t activeLayers, uint32_t scanCode, uint32_t matrix ) {
  int8_t currentLayer;
  uint32_t layerMask = (1<<(NumLayers-1));
  for( currentLayer = NumLayers - 1; currentLayer >= 0; --currentLayer, layerMask >>= 1 )
    if ( ( activeLayers & layerMask ) && ( layers[currentLayer][matrix][scanCode] != KB_Transparent ) )
      return layers[currentLayer][matrix][scanCode];
  return KB_Transparent; }

// updates the keyboard's state from the 4 scanned matrices.
// only one Report is valid at a time, and that report's index is always currentReport.
inputReport_t * ScanCodesToReport ( uint32_t leftFingers,  uint32_t leftThumbs,
				    uint32_t rightFingers, uint32_t rightThumbs ) {
  uint32_t byteCounter, keyCounter, matrixCounter, keyMask = 1;
  uint32_t matrices[4] = {leftFingers, leftThumbs, rightFingers, rightThumbs};
  uint32_t matricesDelta[4] = {0, 0, 0, 0};
  inputReport_t *nextReport = &reportBuffer[(currentReport + 1) % NumReports];
  // copy over old report to make changes
  for( byteCounter = 0; byteCounter < BytesPerReport; ++byteCounter )
    ( ( uint8_t *) nextReport)[ byteCounter ] = 0;
  // generate the keys that have changed
  for( byteCounter = 0; byteCounter < 4; ++byteCounter)
    matricesDelta[ byteCounter ] = matrices[ byteCounter ] ^ oldMatrices[ byteCounter];
  // do layer checking first
  for( keyCounter = 0; keyCounter < 32; ++keyCounter, keyMask <<= 1) 
    for( matrixCounter = 0; matrixCounter < 4; ++matrixCounter) 
      if (keyMask & matricesDelta[matrixCounter]) {
	if (keyMask & matrices[matrixCounter]) { // making key
	  enum KeyNum_t keyNum = ScanCodeToKeyNum( activeLayers, keyCounter, matrixCounter );
	  making[matrixCounter * 32 + keyCounter] = keyNum;
	  if ( (keyNum >= KB_Layer00Enable) && (keyNum <= KB_Layer31Enable) )
	    activeLayers |= 1 << (keyNum - KB_Layer00Enable); } 
	else { //breaking key
	  enum KeyNum_t keyNum = making[matrixCounter * 32 + keyCounter];
	  making[matrixCounter * 32 + keyCounter] = KB_Transparent;
	  if ( (keyNum >= KB_Layer00Enable) && (keyNum <= KB_Layer31Enable) )
	    activeLayers &= ~(1 << (keyNum - KB_Layer00Enable)); } }

  // fallback if things go awry
  if (activeLayers == 0) activeLayers = 1;
	  
  // now do normal keyboard operation with layers enabled by the above
  keyMask = 1;
  for( keyCounter = 0; keyCounter < 32; ++keyCounter, keyMask <<= 1) 
    for( matrixCounter = 0; matrixCounter < 4; ++matrixCounter) 
      if (keyMask & matricesDelta[matrixCounter]) {
	if (keyMask & matrices[matrixCounter]) { // making key
	  enum KeyNum_t keyNum = ScanCodeToKeyNum( activeLayers, keyCounter, matrixCounter );
	  making[matrixCounter * 32 + keyCounter] = keyNum; }
	else { // breaking key
	  making[matrixCounter * 32 + keyCounter] = KB_Transparent; } }

  // making array -> report
  for( keyCounter = 0; keyCounter < 32 * 4; ++keyCounter){
    enum KeyNum_t keyNum = making[ keyCounter ];
    if ( (keyNum < KB_Layer00Enable) && (keyNum != KB_Transparent) )
      ((uint8_t *)nextReport)[(keyNum - KB_LeftControl ) >> 3] |= 1 << ((keyNum - KB_LeftControl) & 0x7 ); }

  currentReport = (currentReport + 1) % NumReports;
  for( matrixCounter = 0; matrixCounter < 4; ++matrixCounter) 
    oldMatrices[matrixCounter] = matrices[matrixCounter];
  return GetCurrentReport( ); }

inputReport_t * GetCurrentReport ( void ) {
  return &reportBuffer[ currentReport ]; }
