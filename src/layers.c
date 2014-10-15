#include "layers.h"
#include "nkro.h"
enum KeyNum_t layers[NumLayers][4][32] =
  // layer 0
  { { { KB_ApostropheAndQuotationMark, KB_CommaAndLessThanSign, KB_PeriodAndGreaterThanSign, KB_P, KB_Y,
	KB_A, KB_O, KB_E, KB_U, KB_I,
	KB_SemicolonAndColon, KB_Q, KB_J, KB_K, KB_X, },
      { KB_LeftShift, KB_KeyboardSpacebar, KB_KeyboardTab, KB_LeftAlt, KB_LeftControl, KB_LeftControl, },
      { KB_F, KB_G, KB_C, KB_R, KB_L,
	KB_D, KB_H, KB_T, KB_N, KB_S,
	KB_B, KB_M, KB_W, KB_V, KB_Z },
      { KB_KeyboardDelete, KB_Layer01Enable, KB_KeyboardEscape, KB_RightAlt, KB_KeyboardReturn, KB_RightGui, }, 
    },
    // layer 1
    { { KB_Transparent, KB_Transparent, KB_Transparent, KB_LeftSquareBracketAndLeftBrace, KB_Transparent,
	KB_Digit1AndExclamationMark,  KB_Digit3AndHash ,  KB_Digit5AndPercent , KB_Digit7AndAmpersand , KB_Digit9AndLeftParenthesis , 
	KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, },
      { KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, },
      { KB_Transparent, KB_RightSquareBracketAndRightBrace, KB_Transparent, KB_Transparent, KB_Transparent,
	KB_Digit0AndRightParenthesis, KB_Digit2AndAtSign, KB_Digit4AndDollar, KB_Digit6AndCaret, KB_Digit8AndAsterisk,
	KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, },
      { KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, },
    }
  };
