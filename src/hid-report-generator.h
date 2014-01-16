#ifndef __HID_REPORT_GENERATOR__
#define __HID_REPORT_GENERATOR__

#include <stdint.h>
#include "nkro.h"

void initReportGernerator ( void );

inputReport_t * ScanCodesToReport ( uint32_t leftFingers,  uint32_t leftThumbs,
				    uint32_t rightFingers, uint32_t rightThumbs );

inputReport_t * GetCurrentReport ( void );

#endif // __HID_REPORT_GENERATOR__
