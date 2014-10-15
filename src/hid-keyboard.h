#ifndef __HID_KEYBOARD__
#define __HID_KEYBOARD__

#include <stdint.h>
#include <stdbool.h>

extern bool USBDHIDKeyboardInit(uint32_t index);
extern bool SendButtons ( ) ;
#endif //__HID_KEYBOARD__
