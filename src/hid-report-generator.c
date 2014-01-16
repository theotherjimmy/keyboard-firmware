
#include "nkro.h"
#include "hid-report-generator.h"
#include "layers.h"
#include <stdint.h>

#define NumReports (2)

inputReport_t reportBuffer[NumReports];
uint8_t currentReport;
uint32_t defaultLayers;

void initReportGernerator ( void ) {
  int reportCounter, byteCounter;
  for( reportCounter = 0; reportCounter < NumReports; ++reportCounter )
    for( byteCounter = 0; byteCounter < BytesPerReport; ++byteCounter )
      ( ( uint8_t *) &reportBuffer[ reportCounter ])[ byteCounter ] = 0;
  defaultLayers = 1;
  currentReport = 0;
}

enum KeyNum_t ScanCodeToKeyNum ( uint32_t activeLayers, uint32_t scanCode, uint32_t matrix ) {
  int8_t currentLayer;
  uint32_t layerMask = (1<<(NumLayers-1));
  for( currentLayer = NumLayers - 1; currentLayer >= 0; --currentLayer, layerMask >>= 1 )
    if ( ( activeLayers & layerMask ) && ( layers[currentLayer][matrix][scanCode] != KB_Transparent ) )
      return layers[currentLayer][matrix][scanCode];
  return KB_Transparent;
}

// updates the keyboard's state from the 4 scanned matrices.
// only one Report is valid at a time, and that report's index is always currentReport.
inputReport_t * ScanCodesToReport ( uint32_t leftFingers,  uint32_t leftThumbs,
				    uint32_t rightFingers, uint32_t rightThumbs ) {
  uint32_t byteCounter, keyCounter, matrixCounter, keyMask = 1;
  uint32_t activeLayers = defaultLayers;
  uint32_t matrices[4] = {leftFingers, leftThumbs, rightFingers, rightThumbs};
  inputReport_t *nextReport = &reportBuffer[(currentReport + 1) % NumReports];
  for( byteCounter = 0; byteCounter < BytesPerReport; ++byteCounter )
    ( ( uint8_t *) nextReport)[ byteCounter ] = 0;
  // do layer checking first
  for( keyCounter = 0; keyCounter < 32; ++keyCounter, keyMask <<= 1) 
    for( matrixCounter = 0; matrixCounter < 4; ++matrixCounter) 
      if (keyMask & matrices[matrixCounter]) {
	enum KeyNum_t keyNum = ScanCodeToKeyNum( defaultLayers, keyCounter, matrixCounter );
	if ( (keyNum >= KB_Layer00Enable) && (keyNum <= KB_Layer31Enable) )
	  activeLayers |= 1 << (keyNum - KB_Layer00Enable); } // not too bad
  // now do normal keyboard operation with layers enabled by the above
  keyMask = 1;
  for( keyCounter = 0; keyCounter < 32; ++keyCounter, keyMask <<= 1) 
    for( matrixCounter = 0; matrixCounter < 4; ++matrixCounter) 
      if (keyMask & matrices[matrixCounter]) {
	enum KeyNum_t keyNum = ScanCodeToKeyNum( activeLayers, keyCounter, matrixCounter );
	if ( (keyNum < KB_Layer00Enable) && (keyNum != KB_Transparent) )
	  ((uint8_t *)nextReport)[(keyNum - KB_LeftControl ) >> 3] |= 1 << ((keyNum - KB_LeftControl) & 0x7 ); } // wow
  currentReport = (currentReport + 1) % NumReports;
  return GetCurrentReport( );
}

inputReport_t * GetCurrentReport ( void ) {
  return &reportBuffer[ currentReport ];
}
