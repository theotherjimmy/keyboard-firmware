#ifndef __NKRO__
#define __NKRO__

#include <stdint.h>

//generated by the usb.org hid descriptor generator

extern uint8_t ReportDescriptor[39];

//generated from the above descriptor with the hidrdd tool

//--------------------------------------------------------------------------------
// Keyboard/Keypad Page inputReport 0 (Device --> Host)
//--------------------------------------------------------------------------------
__extension__
typedef struct
{
                                                     // No REPORT ID byte
                                                     // Collection: Keyboard
  uint8_t  KB_KeyboardKeyboardLeftControl : 1;       // 0007 00E0 Keyboard Left Control (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardLeftShift : 1;         // 0007 00E1 Keyboard Left Shift (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardLeftAlt : 1;           // 0007 00E2 Keyboard Left Alt (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardLeftGui : 1;           // 0007 00E3 Keyboard Left GUI (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardRightControl : 1;      // 0007 00E4 Keyboard Right Control (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardRightShift : 1;        // 0007 00E5 Keyboard Right Shift (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardRightAlt : 1;          // 0007 00E6 Keyboard Right Alt (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardRightGui : 1;          // 0007 00E7 Keyboard Right GUI (DV=Dynamic Value) Value = 0 to 1
  uint8_t  KB_KeyboardA : 1;                         // 0007 0004 Keyboard a and A (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardB : 1;                         // 0007 0005 Keyboard b and B (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardC : 1;                         // 0007 0006 Keyboard c and C (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardD : 1;                         // 0007 0007 Keyboard d and D (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardE : 1;                         // 0007 0008 Keyboard e and E (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardF : 1;                         // 0007 0009 Keyboard f and F (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardG : 1;                         // 0007 000A Keyboard g and G (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardH : 1;                         // 0007 000B Keyboard h and H (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardI : 1;                         // 0007 000C Keyboard i and I (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardJ : 1;                         // 0007 000D Keyboard j and J (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardK : 1;                         // 0007 000E Keyboard k and K (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardL : 1;                         // 0007 000F Keyboard l and L (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardM : 1;                         // 0007 0010 Keyboard m and M (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardN : 1;                         // 0007 0011 Keyboard n and N (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardO : 1;                         // 0007 0012 Keyboard o and O (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardP : 1;                         // 0007 0013 Keyboard p and P (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardQ : 1;                         // 0007 0014 Keyboard q and Q (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardR : 1;                         // 0007 0015 Keyboard r and R (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardS : 1;                         // 0007 0016 Keyboard s and S (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardT : 1;                         // 0007 0017 Keyboard t and T (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardU : 1;                         // 0007 0018 Keyboard u and U (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardV : 1;                         // 0007 0019 Keyboard v and V (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardW : 1;                         // 0007 001A Keyboard w and W (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardX : 1;                         // 0007 001B Keyboard x and X (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardY : 1;                         // 0007 001C Keyboard y and Y (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardZ : 1;                         // 0007 001D Keyboard z and Z (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit1AndExclamationMark : 1;  // 0007 001E Keyboard 1 and ! (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit2AndAtSign : 1;           // 0007 001F Keyboard 2 and @ (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit3AndHash : 1;             // 0007 0020 Keyboard 3 and # (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit4AndDollar : 1;           // 0007 0021 Keyboard 4 and $ (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit5AndPercent : 1;          // 0007 0022 Keyboard 5 and % (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit6AndCaret : 1;            // 0007 0023 Keyboard 6 and ^ (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit7AndAmpersand : 1;        // 0007 0024 Keyboard 7 and & (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit8AndAsterisk : 1;         // 0007 0025 Keyboard 8 and * (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit9AndLeftParenthesis : 1;  // 0007 0026 Keyboard 9 and ( (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardDigit0AndRightParenthesis : 1; // 0007 0027 Keyboard 0 and ) (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardReturn : 1;            // 0007 0028 Keyboard Return (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardEscape : 1;            // 0007 0029 Keyboard Escape (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardDelete : 1;            // 0007 002A Keyboard Delete (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardTab : 1;               // 0007 002B Keyboard Tab (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardSpacebar : 1;          // 0007 002C Keyboard Spacebar (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardHyphenAndUnderscore : 1;       // 0007 002D Keyboard - and _ (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardEqualsAndPlus : 1;             // 0007 002E Keyboard = and + (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardLeftSquareBracketAndLeftBrace : 1; // 0007 002F Keyboard [ and { (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardRightSquareBracketAndRightBrace : 1; // 0007 0030 Keyboard ] and } (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardBackslashAndVerticalBar : 1;   // 0007 0031 Keyboard \ and | (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardSemicolonAndColon : 1;         // 0007 0033 Keyboard ; and : (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardApostropheAndQuotationMark : 1; // 0007 0034 Keyboard ' and " (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardGraveAndTilde : 1;             // 0007 0035 Keyboard ` and ~ (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardCommaAndLessThanSign : 1;      // 0007 0036 Keyboard Comma and < (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardPeriodAndGreaterThanSign : 1;  // 0007 0037 Keyboard . and > (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardSlashAndQuestionMark : 1;      // 0007 0038 Keyboard / and ? (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardCapsLock : 1;          // 0007 0039 Keyboard Caps Lock (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF1 : 1;                // 0007 003A Keyboard F1 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF2 : 1;                // 0007 003B Keyboard F2 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF3 : 1;                // 0007 003C Keyboard F3 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF4 : 1;                // 0007 003D Keyboard F4 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF5 : 1;                // 0007 003E Keyboard F5 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF6 : 1;                // 0007 003F Keyboard F6 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF7 : 1;                // 0007 0040 Keyboard F7 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF8 : 1;                // 0007 0041 Keyboard F8 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF9 : 1;                // 0007 0042 Keyboard F9 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF10 : 1;               // 0007 0043 Keyboard F10 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF11 : 1;               // 0007 0044 Keyboard F11 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardF12 : 1;               // 0007 0045 Keyboard F12 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardPrintScreen : 1;       // 0007 0046 Keyboard Print Screen (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardScrollLock : 1;        // 0007 0047 Keyboard Scroll Lock (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardPause : 1;             // 0007 0048 Keyboard Pause (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardInsert : 1;            // 0007 0049 Keyboard Insert (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardHome : 1;              // 0007 004A Keyboard Home (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardPageUp : 1;            // 0007 004B Keyboard Page Up (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardDeleteForward : 1;     // 0007 004C Keyboard Delete Forward (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardEnd : 1;               // 0007 004D Keyboard End (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardPageDown : 1;          // 0007 004E Keyboard Page Down (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardRightArrow : 1;        // 0007 004F Keyboard Right Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardLeftArrow : 1;         // 0007 0050 Keyboard Left Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardDownArrow : 1;         // 0007 0051 Keyboard Down Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeyboardUpArrow : 1;           // 0007 0052 Keyboard Up Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadNumLockAndClear : 1;     // 0007 0053 Keypad Num Lock and Clear (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadSlash : 1;               // 0007 0054 Keypad / (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadAsterisk : 1;            // 0007 0055 Keypad * (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadComma : 1;               // 0007 0056 Keypad Comma (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadPlus : 1;                // 0007 0057 Keypad + (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadEnter : 1;               // 0007 0058 Keypad Enter (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit1AndEnd : 1;        // 0007 0059 Keypad 1 and End (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit2AndDownArrow : 1;  // 0007 005A Keypad 2 and Down Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit3AndPageDown : 1;   // 0007 005B Keypad 3 and PageDn (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit4AndLeftArrow : 1;  // 0007 005C Keypad 4 and Left Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit5 : 1;              // 0007 005D Keypad 5 (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit6AndRightArrow : 1; // 0007 005E Keypad 6 and Right Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit7AndHome : 1;       // 0007 005F Keypad 7 and Home (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit8AndUpArrow : 1;    // 0007 0060 Keypad 8 and Up Arrow (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit9AndPageUp : 1;     // 0007 0061 Keypad 9 and PageUp (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDigit0AndInsert : 1;     // 0007 0062 Keypad 0 and Insert (Sel=Selector) Value = 0 to 1
  uint8_t  KB_KeyboardKeypadDecimalPointandDelete : 1; // 0007 0063 Keypad . and Delete (Sel=Selector) Value = 0 to 1
} inputReport_t;

#define BytesPerReport (sizeof(inputReport_t) / sizeof(uint8_t))

//generated by hand from the above struct

enum KeyNum_t {
  KB_Transparent = 0,
  KB_LeftControl ,       
  KB_LeftShift ,         
  KB_LeftAlt ,           
  KB_LeftGui ,           
  KB_RightControl ,      
  KB_RightShift ,        
  KB_RightAlt ,          
  KB_RightGui ,          
  KB_A ,                         
  KB_B ,                         
  KB_C ,                         
  KB_D ,                         
  KB_E ,                         
  KB_F ,                         
  KB_G ,                         
  KB_H ,                         
  KB_I ,                         
  KB_J ,                         
  KB_K ,                         
  KB_L ,                         
  KB_M ,                         
  KB_N ,                         
  KB_O ,                         
  KB_P ,                         
  KB_Q ,                         
  KB_R ,                         
  KB_S ,                         
  KB_T ,                         
  KB_U ,                         
  KB_V ,                         
  KB_W ,                         
  KB_X ,                         
  KB_Y ,                         
  KB_Z ,                         
  KB_Digit1AndExclamationMark ,  
  KB_Digit2AndAtSign ,           
  KB_Digit3AndHash ,             
  KB_Digit4AndDollar ,           
  KB_Digit5AndPercent ,          
  KB_Digit6AndCaret ,            
  KB_Digit7AndAmpersand ,        
  KB_Digit8AndAsterisk ,         
  KB_Digit9AndLeftParenthesis ,  
  KB_Digit0AndRightParenthesis , 
  KB_KeyboardReturn ,            
  KB_KeyboardEscape ,            
  KB_KeyboardDelete ,            
  KB_KeyboardTab ,               
  KB_KeyboardSpacebar ,          
  KB_HyphenAndUnderscore ,       
  KB_EqualsAndPlus ,             
  KB_LeftSquareBracketAndLeftBrace , 
  KB_RightSquareBracketAndRightBrace , 
  KB_BackslashAndVerticalBar ,   
  KB_SemicolonAndColon ,         
  KB_ApostropheAndQuotationMark , 
  KB_GraveAndTilde ,             
  KB_CommaAndLessThanSign ,      
  KB_PeriodAndGreaterThanSign ,  
  KB_SlashAndQuestionMark ,      
  KB_CapsLock ,          
  KB_F1 ,                
  KB_F2 ,                
  KB_F3 ,                
  KB_F4 ,                
  KB_F5 ,                
  KB_F6 ,                
  KB_F7 ,                
  KB_F8 ,                
  KB_F9 ,                
  KB_F10 ,               
  KB_F11 ,               
  KB_F12 ,               
  KB_PrintScreen ,       
  KB_ScrollLock ,        
  KB_Pause ,             
  KB_Insert ,            
  KB_Home ,              
  KB_PageUp ,            
  KB_DeleteForward ,     
  KB_End ,               
  KB_PageDown ,          
  KB_RightArrow ,        
  KB_LeftArrow ,         
  KB_DownArrow ,         
  KB_UpArrow ,           
  KB_KeypadNumLockAndClear ,     
  KB_KeypadSlash ,               
  KB_KeypadAsterisk ,            
  KB_KeypadComma ,               
  KB_KeypadPlus ,                
  KB_KeypadEnter ,               
  KB_KeypadDigit1AndEnd ,        
  KB_KeypadDigit2AndDownArrow ,  
  KB_KeypadDigit3AndPageDown ,   
  KB_KeypadDigit4AndLeftArrow ,  
  KB_KeypadDigit5 ,              
  KB_KeypadDigit6AndRightArrow , 
  KB_KeypadDigit7AndHome ,       
  KB_KeypadDigit8AndUpArrow ,    
  KB_KeypadDigit9AndPageUp ,     
  KB_KeypadDigit0AndInsert ,     
  KB_KeypadDecimalPointandDelete , 
  KB_Layer00Enable ,
  KB_Layer01Enable ,
  KB_Layer02Enable ,
  KB_Layer03Enable ,
  KB_Layer04Enable ,
  KB_Layer05Enable ,
  KB_Layer06Enable ,
  KB_Layer07Enable ,
  KB_Layer08Enable ,
  KB_Layer09Enable ,
  KB_Layer10Enable ,
  KB_Layer11Enable ,
  KB_Layer12Enable ,
  KB_Layer13Enable ,
  KB_Layer14Enable ,
  KB_Layer15Enable ,
  KB_Layer16Enable ,
  KB_Layer17Enable ,
  KB_Layer18Enable ,
  KB_Layer19Enable ,
  KB_Layer20Enable ,
  KB_Layer21Enable ,
  KB_Layer22Enable ,
  KB_Layer23Enable ,
  KB_Layer24Enable ,
  KB_Layer25Enable ,
  KB_Layer26Enable ,
  KB_Layer27Enable ,
  KB_Layer28Enable ,
  KB_Layer29Enable ,
  KB_Layer30Enable ,
  KB_Layer31Enable ,
  KB_Macros ,
};

#endif //__NKRO__
