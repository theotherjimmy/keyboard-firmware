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
const uint8_t LangDescriptor[] = {
	4,
	USB_DTYPE_STRING,
	USBShort(USB_LANG_EN_US)
};

//*****************************************************************************
//
// The manufacturer string.
//
//*****************************************************************************
const uint8_t ManufacturerString[] = {
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
const uint8_t ProductString[] = {
	(13 + 1) * 2,
	USB_DTYPE_STRING,
	'K', 0, 'B', 0, 'D', 0, 'F', 0, 'W', 0, ' ', 0, 'E', 0, 'x', 0, 'a', 0,
	'm', 0, 'p', 0, 'l', 0, 'e', 0
};

//*****************************************************************************
//
// The serial number string.
//
//*****************************************************************************
const uint8_t SerialNumberString[] = {
	(8 + 1) * 2,
	USB_DTYPE_STRING,
	'1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0
};

//*****************************************************************************
//
// The descriptor string table.
//
//*****************************************************************************
const uint8_t * const StringDescriptors[] = {
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

static const tConfigSection HIDConfigSection = {
	sizeof(KeybDescriptor),
	KeybDescriptor
};

// HID interface descriptor

static uint8_t HIDInterface[HIDINTERFACE_SIZE] = {
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

static const tConfigSection HIDInterfaceSection = {
	sizeof(HIDInterface),
	HIDInterface
};

// interrupt endpiont descriptors

static const uint8_t HIDInEndpoint[HIDINENDPOINT_SIZE] = {
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

static const tConfigSection HIDInEndpointSection = {
	sizeof(HIDInEndpoint),
	HIDInEndpoint
};

static const uint8_t HIDOutEndpoint[HIDOUTENDPOINT_SIZE] = {
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

static const tConfigSection HIDOutEndpointSection = {
	sizeof(HIDOutEndpoint),
	HIDOutEndpoint
};

// report descriptor

static const tHIDDescriptor KeybHIDDescriptor = {
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

static tConfigSection HIDDescriptorSection = {
	sizeof(KeybHIDDescriptor),
	(const uint8_t *) &KeybHIDDescriptor
};

// section pointers

static const tConfigSection *HIDSections[] = {
	&HIDConfigSection,
	&HIDInterfaceSection,
	&HIDDescriptorSection,
	&HIDInEndpointSection,
	&HIDOutEndpointSection
};

#define NUM_HID_SECTIONS        ((sizeof(HIDSections) / sizeof(HIDSections[0])) - 1)

// the configuration that we support

static tConfigHeader HIDConfigHeader = {
	NUM_HID_SECTIONS,
	HIDSections
};

// the list of all of the configurations we support

static const tConfigHeader * const HIDConfigDescriptors[] = {
	&HIDConfigHeader
};

// descriptor table

static const uint8_t * const KeybClassDescriptors[] = {
	ReportDescriptor
};

typedef struct  {
	bool USBConfigured;
	// the following two components are needed by usblib
	tHIDReportIdle ReportIdle;
	tUSBDHIDDevice HIDDevice;
} USBHIDKeyboardDevice_t;

USBHIDKeyboardDevice_t Device;

static uint8_t buff[1 << 5];

static uint32_t HIDKeyoardRxHandler (void *KeyboardDevice, uint32_t Event,
				     uint32_t MsgValue, void * MsgData) {
        /* otherwise unused */
        MsgValue = MsgValue;
	switch (Event) {
	case USB_EVENT_CONNECTED: {
		((USBHIDKeyboardDevice_t *)KeyboardDevice)->USBConfigured = true;
		break; }
	case USB_EVENT_DISCONNECTED: {
		((USBHIDKeyboardDevice_t *)KeyboardDevice)->USBConfigured = false;
		break; }
	case USBD_HID_EVENT_GET_REPORT: 
	case USBD_HID_EVENT_IDLE_TIMEOUT: {
		*(inputReport_t **)MsgData = GetCurrentReport();
		return sizeof( inputReport_t ) / sizeof( uint8_t );
	}
	case USBD_HID_EVENT_GET_REPORT_BUFFER: {
		if  ((uint32_t)MsgData < 1 << 5)
			return (uint32_t) &buff[0];
		else
			return 0; }
		// we only support the report protocol. Therefore, if asked, we are currently using the report protocol
	case USBD_HID_EVENT_GET_PROTOCOL: { return USB_HID_PROTOCOL_REPORT; }
		// cannot happen, we do not define any input reports, and we stall all attepmts to recieve them.
	case USBD_HID_EVENT_REPORT_SENT:  { 
		return 0; }
	case USB_EVENT_SUSPEND: {
		set_pin(PIN_F2, true);
		break; }
	case USB_EVENT_ERROR:  
	case USBD_HID_EVENT_SET_REPORT: 
	case USBD_HID_EVENT_SET_PROTOCOL: 
	case USB_EVENT_RESUME:
	default : {
		set_pin(PIN_F3, true);
		break; }
	}
	return 0;
}

static uint32_t HIDKeyoardTxHandler (void *KeyboardDevice, uint32_t Event, uint32_t MsgValue, void * MsgData) {
        /* otherwise unused */
        KeyboardDevice = KeyboardDevice;
        Event = Event;
        MsgValue = MsgValue;
        MsgData = MsgData;
	return 0;
}

bool SendButtons ( void ) {
	uint32_t count;
	if(USBDHIDTxPacketAvailable((void *)&Device.HIDDevice))
	{
		//
		// Send the report to the host.
		//
		count = USBDHIDReportWrite((void *)&Device.HIDDevice,
					   (uint8_t *)GetCurrentReport(),
					   sizeof( inputReport_t ) / sizeof( uint8_t ),
					   true);
		
		//
		// Did we schedule a packet for transmission correctly?
		//
		if(count <= 0)
		{
			//
			// No - report the error to the caller.
			//
			return false;
		}
		else return true;
	}
	return false ;
}
bool USBDHIDKeyboardInit(uint32_t index) {
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
	compRet = USBDHIDCompositeInit( index, HIDDevice, 0 );
	initRet = USBDHIDInit( index, HIDDevice );
	return compRet && initRet;
}
