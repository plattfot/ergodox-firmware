/* ----------------------------------------------------------------------------
* ergoDOX layout : QWERTY (modified from the Kinesis layout)
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// DEFINITIONS ----------------------------------------------------------------
#define  mprrel   &kbfun_mediakey_press_release
#define  kprrel   &kbfun_press_release
#define  ktog     &kbfun_toggle
#define  ktrans   &kbfun_transparent
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad
// ----------------------------------------------------------------------------

/*nk == no key*/
// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	0,	
	// Left hand
	KEY_GraveAccent_Tilde,	KEY_1_Exclamation,	        KEY_2_At,	                KEY_3_Pound,	KEY_4_Dollar,	        KEY_5_Percent,	KEY_Escape,	
	KEY_Backslash_Pipe,	KEY_q_Q,	                KEY_w_W,	                KEY_e_E,	KEY_r_R,	        KEY_t_T,	1,	
	KEY_Tab,	        KEY_a_A,	                KEY_s_S,	                KEY_d_D,	KEY_f_F,	        KEY_g_G,	/*no key*/
	KEY_LeftShift,	        KEY_z_Z,	                KEY_x_X,	                KEY_c_C,	KEY_v_V,	        KEY_b_B,	KEY_End,
	KEY_LeftControl,	KEY_RightBracket_RightBrace,	KEY_NonUS_Backslash_Pipe,	KEY_LeftGUI,	KEY_LeftControl,	/*no key*/	/*no key*/
        // Left thumb
        /*no key*/		KEY_DeleteForward,		KEY_ScrollLock,
	0/*no key*/,		0/*no key*/,    		KEY_Home,
	KEY_Spacebar,		KEY_LeftAlt,			3,
        
	// Right hand
	2,			KEY_6_Caret,	 	KEY_7_Ampersand,	KEY_8_Asterisk,		KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,		KEY_Dash_Underscore,	
	KEY_Equal_Plus,		KEY_y_Y,	 	KEY_u_U,		KEY_i_I,		KEY_o_O,		KEY_p_P,			KEY_LeftBracket_LeftBrace,	
	KEY_h_H,		KEY_j_J,	 	KEY_k_K,		KEY_l_L,		KEY_Semicolon_Colon,	KEY_SingleQuote_DoubleQuote,	/*no key*/
	KEY_Insert,		KEY_n_N,	 	KEY_m_M,		KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_Slash_Question,		KEY_RightShift,	
	1,			KEY_RightControl,	KEY_RightAlt,		3,			KEY_RightGUI,		/*no key*/			/*no key*/
        // Right thumb
        KEY_PrintScreen,	KEY_LeftAlt,		/*no key*/
	KEY_RightAlt,		/*no key*/0,		/*no key*/0,	
	KEY_RightControl,	KEY_ReturnEnter,	KEY_DeleteBackspace	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	0,	
	// Left hand
	0,	KEY_F1,		KEY_F2,		KEY_F3,		KEY_F4,		KEY_F5,	KEY_F11,	
	0,	0,		KEY_UpArrow,	0,		KEY_r_R,	0,	1,	
	0,	KEY_LeftArrow,	KEY_DownArrow,	KEY_RightArrow,	0,		0,	/*nk*/
	0,	0,		0,		KEY_c_C,	0,		0,	0,	
	0,	0,		0,		0,		0,		/*nk*/	/*nk*/
        // Left thumb
	 /*nk*/	0,		0,	
	0/*nk*/,0/*nk*/,	0,	
	0,	0,		0,	
	// Right hand
	KEY_F12,	KEY_F6,		KEY_F7,			KEY_F8,				KEY_F9,			KEY_F10,	0,	
	0,		0,		MEDIAKEY_AUDIO_MUTE,	MEDIAKEY_AUDIO_VOL_DOWN,	MEDIAKEY_AUDIO_VOL_UP,	KEY_p_P,	0,	
	0,		KEY_LeftArrow,	KEY_UpArrow,		KEY_DownArrow,			KEY_RightArrow,		0,		/*nk*/
	0,		0,		0,			0,				0,			0,		0,	
	0,		0,		0,			0,				0,			/*no key*/	/*no key*/
        // Right thumb
	0,		0,		/*nk*/
	0,		0/*nk*/,	0/*nk*/,	
	0,		0,		0	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	0,	
	// Left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,
        // Left thumb
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// Right hand
	2,	0,			KEYPAD_NumLock_Clear,	KEYPAD_Slash,		KEYPAD_Asterisk,	KEYPAD_Minus,		0,	
	0,	0,			KEYPAD_7_Home,		KEYPAD_8_UpArrow,	KEYPAD_9_PageUp,	KEYPAD_Plus,		0,	
	0,	KEYPAD_4_LeftArrow,	KEYPAD_5,		KEYPAD_6_RightArrow,	KEYPAD_Plus,		0,	
	0,	0,			KEYPAD_1_End,		KEYPAD_2_DownArrow,	KEYPAD_3_PageDown,	KEY_ReturnEnter,	0,	
	0,	0,			KEYPAD_Period_Delete,	KEY_ReturnEnter,	0,
        // Right thumb
	0,	0,	
	0,	0,	0,	
	0,	0,	KEYPAD_0_Insert	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	0,	
	// Left hand
	0,	0,			0,			0,			0,			0,	0,	
	0,	0,			0,			0,			0,			0,	0,	
	0,	KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,	KEY_Backslash_Pipe,	KEY_Dash_Underscore,	0,	
	0,	0,			0,			0,			0,			0,	0,	
	0,	0,			0,			0,			0,	
        // Left thumb
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// Right hand
	3,			0,	0,	0,				0,				0,	0,	
	0,			0,	0,	0,				0,				0,	0,	
	KEY_Dash_Underscore,	0x2F,	0x30,	KEY_LeftBracket_LeftBrace,	KEY_RightBracket_RightBrace,	0,	
	0,			0,	0,	0,				0,				0,	0,	
	0,			0,	0,	0,				0,
        // Right thumb
	0,	0,	
	0,	0,	0,	
	0,	0,	KEY_DeleteForward	
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
// LAYER 5
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
// LAYER 6
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
// LAYER 7
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
// LAYER 8
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
// LAYER 9
KB_MATRIX_LAYER(
	// unused
	0,	
	// left hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0,	
	// right hand
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	0,	0,	
	0,	0,	0,	0,	0,	
	0,	0,	
	0,	0,	0,	
	0,	0,	0	
),
};
// ----------------------------------------------------------------------------

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpush1,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	lpush3,	
	// right hand
	lpush2,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpush1,	kprrel,	kprrel,	lpush3,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	NULL,	kprrel,	NULL,	lpop1,	
	ktrans,	kprrel,	kprrel,	kprrel,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	kprrel,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	ktrans,	ktrans,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	mprrel,	mprrel,	mprrel,	kprrel,	NULL,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	ktrans,	
	NULL,	ktrans,	ktrans,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	dbtldr,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	ktrans,	ktrans,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL,	
	// right hand
	lpop2,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,   kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	NULL,	NULL,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	kprrel	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	ktrans,	sshprre, sshprre, kprrel, kprrel, NULL,	
	ktrans,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	ktrans,	NULL,	 NULL,	  ktrans, ktrans,	
	NULL,	NULL,	 
	NULL,	NULL,	 NULL,	
	ktrans,	ktrans,	 NULL,	
	// right hand
	lpop3,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	kprrel,	sshprre,	sshprre,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	ktrans,	
	NULL,	ktrans,	ktrans,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	kprrel	
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 5
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 6
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 7
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 8
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 9
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	
	kprrel,	kprrel,	lpop3,	
	// right hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	lpop1,	kprrel,	kprrel,	lpop3,	kprrel,	
	kprrel,	kprrel,	
	kprrel,	NULL,	NULL,	
	kprrel,	kprrel,	kprrel	
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	
	NULL,	NULL,	kprrel,	NULL,	kprrel,	NULL,	NULL,	
	ktrans,	kprrel,	kprrel,	kprrel,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	kprrel,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	ktrans,	ktrans,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL,	
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	mprrel,	mprrel,	mprrel,	kprrel,	NULL,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	ktrans,	
	NULL,	ktrans,	ktrans,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL	
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	ktrans,	NULL,	NULL,	ktrans,	ktrans,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL,	
	// right hand
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	
	NULL,	NULL,	kprrel,	kprrel,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	kprrel	
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	ktrans,	sshprre, sshprre, kprrel, kprrel, NULL,	
	ktrans,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	ktrans,	NULL,	 NULL,	  ktrans, ktrans,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	NULL,	
	// right hand
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	NULL,	
	kprrel,	sshprre, sshprre, kprrel, kprrel, NULL,	
	NULL,	NULL,	 NULL,	  NULL,	  NULL,	  NULL,	ktrans,	
	NULL,	ktrans,	 ktrans,  NULL,	  NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	ktrans,	ktrans,	kprrel	
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 5
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 6
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 7
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 8
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
// LAYER 9
KB_MATRIX_LAYER(
	// unused
	NULL,	
	// left hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	// right hand
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL,	NULL,	NULL,	
	NULL,	NULL,	
	NULL,	NULL,	NULL,	
	NULL,	NULL,	NULL	
),
};
// ----------------------------------------------------------------------------
