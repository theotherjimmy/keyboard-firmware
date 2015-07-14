#include "nkro.h"

uint8_t ReportDescriptor[39] = {
        0x05, 0x01,                         // USAGE_PAGE (Generic Desktop)
        0x09, 0x06,                         // USAGE (Keyboard)
        0xa1, 0x01,                         // COLLECTION (Application)
        0x05, 0x07,                         //   USAGE_PAGE (Keyboard)
        0x15, 0x00,                         //   LOGICAL_MINIMUM (0)
        0x25, 0x01,                         //   LOGICAL_MAXIMUM (1)
        0x75, 0x01,                         //   REPORT_SIZE (1)
        0x19, 0xe0,             //   USAGE_MINIMUM (Keyboard LeftControl)
        0x29, 0xe7,             //   USAGE_MAXIMUM (Keyboard Right GUI)
        0x95, 0x08,             //   REPORT_COUNT (8)
        0x81, 0x02,             //   INPUT (Data,Var,Abs)
        0x19, 0x04,             //   USAGE_MINIMUM (Keyboard a and A)
        0x29, 0x31,             //   USAGE_MAXIMUM (Keyboard \ and |)
        0x95, 0x2e,             //   REPORT_COUNT (46)
        0x81, 0x02,             //   INPUT (Data,Var,Abs)
        0x19, 0x33,             //   USAGE_MINIMUM (Keyboard ; and :)
        0x29, 0x63,             //   USAGE_MAXIMUM (Keypad . and Delete)
        0x95, 0x31,             //   REPORT_COUNT (49)
        0x81, 0x02,             //   INPUT (Data,Var,Abs)
        0xc0                    // END_COLLECTION
};
