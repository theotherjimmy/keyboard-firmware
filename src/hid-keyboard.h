#ifndef __HID_KEYBOARD__
#define __HID_KEYBOARD__

#include <stdint.h>
#include <stdbool.h>

extern bool USBDHIDKeyboardInit(uint32_t index, keymatrix_t * to_scan_left, keymatrix_t * to_scan_right,
				keymatrix_t * to_scan_thumb_left, keymatrix_t * to_scan_thumb_right);

#endif //__HID_KEYBOARD__
