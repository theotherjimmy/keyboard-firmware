#include "layers.h"
#include "nkro.h"
enum KeyNum_t layers[NumLayers][4][32] =
{
	// layer 0
	{
		{ KB_Q, KB_W, KB_E, KB_R, KB_T,
		  KB_A, KB_S, KB_D, KB_F, KB_G,
		  KB_Z, KB_X, KB_C, KB_V, KB_B, },
		{ KB_LeftShift, KB_KeyboardSpacebar, KB_KeyboardTab, KB_LeftAlt, KB_LeftControl, KB_LeftControl, },
		{ KB_Y, KB_U, KB_I, KB_O, KB_P,
		  KB_H, KB_J, KB_K, KB_L, KB_SemicolonAndColon,
		  KB_N, KB_M, KB_CommaAndLessThanSign, KB_PeriodAndGreaterThanSign, KB_SlashAndQuestionMark },
		{ KB_Layer01Enable, KB_KeyboardDelete, KB_KeyboardEscape, KB_RightAlt, KB_KeyboardReturn, KB_RightControl, }, 
	},
	// layer 1
	{
		{ KB_Transparent, KB_Transparent, KB_Transparent, KB_HyphenAndUnderscore, KB_LeftArrow,
		  KB_Digit1AndExclamationMark,  KB_Digit3AndHash ,  KB_Digit5AndPercent , KB_Digit7AndAmpersand , KB_Digit9AndLeftParenthesis , 
		  KB_Transparent, KB_Transparent, KB_LeftSquareBracketAndLeftBrace, KB_ApostropheAndQuotationMark, KB_RightArrow, },
		{ KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, },
		{ KB_UpArrow, KB_EqualsAndPlus, KB_Transparent, KB_Transparent, KB_Transparent,
		  KB_Digit0AndRightParenthesis, KB_Digit2AndAtSign, KB_Digit4AndDollar, KB_Digit6AndCaret, KB_Digit8AndAsterisk,
		  KB_DownArrow, KB_BackslashAndVerticalBar, KB_RightSquareBracketAndRightBrace, KB_Transparent, KB_Transparent,  },
		{ KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, KB_Transparent, },
	}
};
