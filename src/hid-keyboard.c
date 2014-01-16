#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <inc/hw_types.h>
#include <driverlib/debug.h>
#include <driverlib/usb.h>
#include <usblib/usblib.h>
#include <usblib/usblibpriv.h>
#include <usblib/device/usbdevice.h>
#include <usblib/usbhid.h>
#include <usblib/device/usbdhid.h>

#include "nkro.h"
#include "matrix-driver.h"
#include "hid-report-generator.h"

//*****************************************************************************
//
// The languages supported by this device.
//
//*****************************************************************************
const uint8_t LangDescriptor[] =
{
    4,
    USB_DTYPE_STRING,
    USBShort(USB_LANG_EN_US)
};

//*****************************************************************************
//
// The manufacturer string.
//
//*****************************************************************************
const uint8_t ManufacturerString[] =
{
    (17 + 1) * 2,
    USB_DTYPE_STRING,
    'T', 0, 'e', 0, 'x', 0, 'a', 0, 's', 0, ' ', 0, 'I', 0, 'n', 0, 's', 0,
    't', 0, 'r', 0, 'u', 0, 'm', 0, 'e', 0, 'n', 0, 't', 0, 's', 0,
};

//*****************************************************************************
//
// The product string.
//
//*****************************************************************************
const uint8_t ProductString[] =
{
    (13 + 1) * 2,
    USB_DTYPE_STRING,
    'M', 0, 'o', 0, 'u', 0, 's', 0, 'e', 0, ' ', 0, 'E', 0, 'x', 0, 'a', 0,
    'm', 0, 'p', 0, 'l', 0, 'e', 0
};

//*****************************************************************************
//
// The serial number string.
//
//*****************************************************************************
const uint8_t SerialNumberString[] =
{
    (8 + 1) * 2,
    USB_DTYPE_STRING,
    '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0
};

//*****************************************************************************
//
// The descriptor string table.
//
//*****************************************************************************
const uint8_t * const StringDescriptors[] =
{
    LangDescriptor,
    ManufacturerString,
    ProductString,
    SerialNumberString,
};

#define NUM_STRING_DESCRIPTORS (sizeof(StringDescriptors) / sizeof(uint8_t *))

// HID device configuration descrpitor

static uint8_t KeybDescriptor[] = {
  9,                          // Size of the configuration descriptor.
  USB_DTYPE_CONFIGURATION,    // Type of this descriptor.
  USBShort(34),               // The total size of this full structure.
  1,                          // The number of interfaces in this configuration.
  1,                          // The unique value for this configuration.
  5,                          // The string identifier that describes this configuration.
  USB_CONF_ATTR_SELF_PWR,     // Bus Powered, Self Powered, remote wake up.
  250,                        // The maximum power in 2mA increments.
};

// associated section

static const tConfigSection HIDConfigSection =
{
    sizeof(KeybDescriptor),
    KeybDescriptor
};

// HID interface descriptor

static uint8_t HIDInterface[HIDINTERFACE_SIZE] =
{
  9,                          // Size of the interface descriptor.
  USB_DTYPE_INTERFACE,        // Type of this descriptor.
  0,                          // The index for this interface.
  0,                          // The alternate setting for this interface.
  1,                          // The number of endpoints used by this interface.
  USB_CLASS_HID,              // The interface class
  USB_HID_SCLASS_NONE,        // The interface sub-class.
  USB_HID_PROTOCOL_KEYB,      // The interface protocol for the sub-class specified above.
  4,                          // The string index for this interface.
};

// associated section

static const tConfigSection HIDInterfaceSection =
{
    sizeof(HIDInterface),
    HIDInterface
};

// interrupt endpiont descriptors

static const uint8_t HIDInEndpoint[HIDINENDPOINT_SIZE] =
{
  //
  // Interrupt IN endpoint descriptor
  //
  7,                          // The size of the endpoint descriptor.
  USB_DTYPE_ENDPOINT,         // Descriptor type is an endpoint.
  USB_EP_DESC_IN | USBEPToIndex(USB_EP_1),
  USB_EP_ATTR_INT,            // Endpoint is an interrupt endpoint.
  USBShort(USBFIFOSizeToBytes(USB_FIFO_SZ_64)), // The maximum packet size.
  16,                         // The polling interval for this endpoint.
};

static const tConfigSection HIDInEndpointSection =
{
    sizeof(HIDInEndpoint),
    HIDInEndpoint
};

static const uint8_t HIDOutEndpoint[HIDOUTENDPOINT_SIZE] =
{
  //
  // Interrupt OUT endpoint descriptor
  //
  7,                          // The size of the endpoint descriptor.
  USB_DTYPE_ENDPOINT,         // Descriptor type is an endpoint.
  USB_EP_DESC_OUT | USBEPToIndex(USB_EP_2),
  USB_EP_ATTR_INT,            // Endpoint is an interrupt endpoint.
  USBShort(USBFIFOSizeToBytes(USB_FIFO_SZ_64)), // The maximum packet size.
  16,                         // The polling interval for this endpoint.
};

static const tConfigSection HIDOutEndpointSection =
{
    sizeof(HIDOutEndpoint),
    HIDOutEndpoint
};

// report descriptor

static const tHIDDescriptor KeybHIDDescriptor =
{
  9,                              // bLength
  USB_HID_DTYPE_HID,              // bDescriptorType
  0x111,                          // bcdHID (version 1.11 compliant)
  0,                              // bCountryCode (not localized)
  1,                              // bNumDescriptors
  {
    {
      USB_HID_DTYPE_REPORT,       // Report descriptor
      sizeof(ReportDescriptor)    // Size of report descriptor
    }
  }
};

// associated section

static tConfigSection HIDDescriptorSection =
{
   sizeof(KeybHIDDescriptor),
   (const uint8_t *) &KeybHIDDescriptor
};

// section pointers

static const tConfigSection *HIDSections[] =
{
    &HIDConfigSection,
    &HIDInterfaceSection,
    &HIDDescriptorSection,
    &HIDInEndpointSection,
    &HIDOutEndpointSection
};

#define NUM_HID_SECTIONS        ((sizeof(HIDSections) / sizeof(HIDSections[0])) - 1)

// the configuration that we support

static tConfigHeader HIDConfigHeader =
{
  NUM_HID_SECTIONS,
  HIDSections
};

// the list of all of the configurations we support

static const tConfigHeader * const HIDConfigDescriptors[] =
{
    &HIDConfigHeader
};

// descriptor table

static const uint8_t * const KeybClassDescriptors[] =
{
    ReportDescriptor
};


typedef struct  {
  bool USBConfigured;
  // the following two components are needed by usblib
  tHIDReportIdle ReportIdle;
  tUSBDHIDDevice HIDDevice;
  keymatrix_t * to_scan_left;
  keymatrix_t * to_scan_right;
  keymatrix_t * to_scan_thumb_left;
  keymatrix_t * to_scan_thumb_right;
} USBHIDKeyboardDevice_t;
  
USBHIDKeyboardDevice_t Device;

static uint32_t HIDKeyoardRxHandler (void *KeyboardDevice, uint32_t Event, uint32_t MsgValue, void * MsgData) {
  printf("USB event: %x\r\n", (int) Event);
  switch (Event) {
  case USB_EVENT_CONNECTED: {
    ((USBHIDKeyboardDevice_t *)KeyboardDevice)->USBConfigured = true;
    printf("connected\r\n");
    break; }
  case USB_EVENT_DISCONNECTED: {
    ((USBHIDKeyboardDevice_t *)KeyboardDevice)->USBConfigured = false;
    printf("disconnected\r\n");
    break; }
  case USBD_HID_EVENT_GET_REPORT: 
  case USBD_HID_EVENT_IDLE_TIMEOUT: {
    inputReport_t * report;
    int i;
    USBHIDKeyboardDevice_t * Device = (USBHIDKeyboardDevice_t *) KeyboardDevice;
    report  = ScanCodesToReport( scan_matrix( Device->to_scan_left ),
						    scan_matrix( Device->to_scan_thumb_left ),
						    scan_matrix( Device->to_scan_right ),
						    scan_matrix( Device->to_scan_thumb_left ) );
    *(inputReport_t **)MsgData = report;
    printf( "HID Report =" );
    for( i = sizeof( inputReport_t ) ; i > 0; --i) {
      if (i < sizeof( inputReport_t ) ) printf( ":" );
      printf( "%02X",( ( uint8_t * )report )[ i - 1 ] ); }
    printf( "\r\n" );
    return sizeof( inputReport_t );
  }
  case USBD_HID_EVENT_GET_REPORT_BUFFER: { return 0; }
    // we only support the report protocol. Therefore, if asked, we are currently using the report protocol
  case USBD_HID_EVENT_GET_PROTOCOL: { return USB_HID_PROTOCOL_REPORT; }
    // cannot happen, we do not define any input reports, and we stall all attepmts to recieve them.
  case USBD_HID_EVENT_REPORT_SENT: { printf( "report sent \r\n" );  break; }
  case USBD_HID_EVENT_SET_REPORT: 
  case USBD_HID_EVENT_SET_PROTOCOL: 
  case USB_EVENT_ERROR:{ printf( "error \r\n" ); break; }
  case USB_EVENT_SUSPEND:{ printf( "suspend \r\n" ); break; }
  case USB_EVENT_RESUME:{ printf( "resume \r\n" ); break; }
  default : { break; }
  }
  return 0;
}

static uint32_t HIDKeyoardTxHandler (void *KeyboardDevice, uint32_t Event, uint32_t MsgValue, void * MsgData) {
  return 0;
}
  
bool USBDHIDKeyboardInit(uint32_t index, keymatrix_t * to_scan_left, keymatrix_t * to_scan_right,
			 keymatrix_t * to_scan_thumb_left, keymatrix_t * to_scan_thumb_right) {
  tUSBDHIDDevice *HIDDevice;
  bool compRet, initRet;
  initReportGernerator( );
  HIDDevice = &Device.HIDDevice;
  HIDDevice->ui16PID = 0x1CBE;
  HIDDevice->ui16VID = 0x000D;
  HIDDevice->ui16MaxPowermA = 500;
  HIDDevice->ui8PwrAttributes = 0;
  HIDDevice->ui8Subclass = USB_HID_SCLASS_NONE;
  HIDDevice->ui8Protocol = USB_HID_PROTOCOL_KEYB;
  HIDDevice->ui8NumInputReports = 1;
  HIDDevice->pfnRxCallback = HIDKeyoardRxHandler;
  HIDDevice->pvRxCBData = (void *)&Device;
  HIDDevice->pfnTxCallback = HIDKeyoardTxHandler; 
  HIDDevice->pvTxCBData = (void *)&Device;
  HIDDevice->psHIDDescriptor = &KeybHIDDescriptor;
  HIDDevice->ppui8ClassDescriptors = KeybClassDescriptors;
  HIDDevice->ppui8StringDescriptors = &StringDescriptors[ 0 ];
  HIDDevice->ui32NumStringDescriptors = NUM_STRING_DESCRIPTORS ;
  HIDDevice->ppsConfigDescriptor = HIDConfigDescriptors;
  HIDDevice->psReportIdle = &Device.ReportIdle;
  Device.ReportIdle.ui8Duration4mS = 125;
  Device.to_scan_left = to_scan_left;
  Device.to_scan_right = to_scan_right;
  Device.to_scan_thumb_left = to_scan_thumb_left;
  Device.to_scan_thumb_right = to_scan_thumb_right;
  compRet = USBDHIDCompositeInit( index, HIDDevice, 0 );
  initRet = USBDHIDInit( index, HIDDevice );
  return compRet && initRet;
}
