#ifndef CONTROL_H
#define CONTROL_H

//Allegro libraries
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>

//Other libraries needed
#include <string>

//EVENTS
//Types of events
enum eventType
{
	EVENT_JOYSTICK_AXIS = 1,
	EVENT_JOYSTICK_BUTTON_DOWN = 2,
	EVENT_JOYSTICK_BUTTON_UP = 3,
	EVENT_JOYSTICK_CONFIGURATION = 4,

	EVENT_KEY_DOWN = 10, //Key pressed
	EVENT_KEY_CHAR = 11,
	EVENT_KEY_UP = 12, //Key unpressed

	EVENT_MOUSE_AXES = 20,
	EVENT_MOUSE_BUTTON_DOWN = 21,
	EVENT_MOUSE_BUTTON_UP = 22,
	EVENT_MOUSE_ENTER_DISPLAY = 23,
	EVENT_MOUSE_LEAVE_DISPLAY = 24,
	EVENT_MOUSE_WARPED = 25,

	EVENT_TIMER = 30, //Event of a timer.
	
	EVENT_DISPLAY_EXPOSE = 40,
	EVENT_DISPLAY_RESIZE = 41,
	EVENT_DISPLAY_CLOSE = 42, //Event clicking on the closing button of the display.
	EVENT_DISPLAY_LOST = 43,
	EVENT_DISPLAY_FOUND = 44,
	EVENT_DISPLAY_SWITCH_IN = 45,
	EVENT_DISPLAY_SWITCH_OUT = 46,
	EVENT_DISPLAY_ORIENTATION = 47,
	EVENT_DISPLAY_HALT_DRAWING = 48,
	EVENT_DISPLAY_RESUME_DRAWING = 49,

	EVENT_TOUCH_BEGIN = 50,
	EVENT_TOUCH_END = 51,
	EVENT_TOUCH_MOVE = 52,
	EVENT_TOUCH_CANCEL = 53,

	EVENT_DISPLAY_CONNECTED = 60,
	EVENT_DISPLAY_DISCONNECTED = 61
};
//Creates an event queue and registers some types of events. | PARAMETERS: Screen, Timer, Event queue and a sort of booleans indicating which kind of events the game uses. 
void initializeEvent(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE * &event_queue, bool use_display, bool use_keyboard, bool use_mouse);
//Waits until an event happens | PARAMETERS: Event queue, Event.
void waitEvent(ALLEGRO_EVENT_QUEUE * &event_queue, ALLEGRO_EVENT &events);
//Destroys event queue | PARAMETERS: Event queue.
void destroyEvent(ALLEGRO_EVENT_QUEUE * &event_queue);
//Waits for the specified number of seconds | PARAMETERS: seconds.
void waitSeconds(double seconds);

//DISPLAY
//Types of screens
enum screenType { standard, fullscreen, fullscreen_window, resizable, noframe };
//Types of boxes
enum boxType {
	MESSAGEBOX_WARN = ALLEGRO_MESSAGEBOX_WARN,
	MESSAGEBOX_ERROR = ALLEGRO_MESSAGEBOX_ERROR,
	MESSAGEBOX_OK_CANCEL = ALLEGRO_MESSAGEBOX_OK_CANCEL,
	MESSAGEBOX_YES_NO = ALLEGRO_MESSAGEBOX_YES_NO,
	MESSAGEBOX_QUESTION = ALLEGRO_MESSAGEBOX_QUESTION
};
//Creates a display. | PARAMETERS: display pointer, height, width, positionX where it appears, positionY where it appears, ScreenTitle and the type of screen (see ScreenType enum for different types).
void createDisplay(ALLEGRO_DISPLAY * &display, int const& screenHeight, int const& screenWidth, int const& screen_x_position, int const& screen_y_position, std::string screenName, screenType const& screenType, ALLEGRO_BITMAP *icon);
//Destroys a display. | PARAMETERS: display pointer.
void destroyDisplay(ALLEGRO_DISPLAY * &display);
//Creates and shows a message box. | PARAMETERS: display, title, heading, text.
void createMessageBox(ALLEGRO_DISPLAY *display, std::string title, std::string heading, std::string text, boxType box_type);

//TIMER
//Creates a timer with a speed of 1/FPS. A timer will generate an event each 1/FPS. | PARAMETERS: Timer pointer, FPS.
void createTimer(ALLEGRO_TIMER * &timer, const double FPS);
//Registers a specific timer to the event queue. | PARAMETERS: Event queue, timer.
void registerTimer(ALLEGRO_EVENT_QUEUE * &event_queue, ALLEGRO_TIMER *timer);
//Starts a timer so that it begins to generate events. | PARAMETERS: Timer pointer.
void startTimer(ALLEGRO_TIMER *timer);
//Stops a timer so that it stops generating events. | PARAMETERS: Timer pointer.
void stopTimer(ALLEGRO_TIMER *timer);
//Destroys a timer freeing the memmory and resources. | PARAMETERS: Timer pointer.
void destroyTimer(ALLEGRO_TIMER * &timer);

//KEYBOARD
//Keyboard codes
enum keycodes
{
	//Keyboard letters
	KEY_A = 1,
	KEY_B = 2,
	KEY_C = 3,
	KEY_D = 4,
	KEY_E = 5,
	KEY_F = 6,
	KEY_G = 7,
	KEY_H = 8,
	KEY_I = 9,
	KEY_J = 10,
	KEY_K = 11,
	KEY_L = 12,
	KEY_M = 13,
	KEY_N = 14,
	KEY_O = 15,
	KEY_P = 16,
	KEY_Q = 17,
	KEY_R = 18,
	KEY_S = 19,
	KEY_T = 20,
	KEY_U = 21,
	KEY_V = 22,
	KEY_W = 23,
	KEY_X = 24,
	KEY_Y = 25,
	KEY_Z = 26,
	//Keyboard numbers
	KEY_0 = 27,
	KEY_1 = 28,
	KEY_2 = 29,
	KEY_3 = 30,
	KEY_4 = 31,
	KEY_5 = 32,
	KEY_6 = 33,
	KEY_7 = 34,
	KEY_8 = 35,
	KEY_9 = 36,
	//Keyboard pad numbers
	KEY_PAD_0 = 37,
	KEY_PAD_1 = 38,
	KEY_PAD_2 = 39,
	KEY_PAD_3 = 40,
	KEY_PAD_4 = 41,
	KEY_PAD_5 = 42,
	KEY_PAD_6 = 43,
	KEY_PAD_7 = 44,
	KEY_PAD_8 = 45,
	KEY_PAD_9 = 46,
	//Keyboard Fkeys
	KEY_F1 = 47,
	KEY_F2 = 48,
	KEY_F3 = 49,
	KEY_F4 = 50,
	KEY_F5 = 51,
	KEY_F6 = 52,
	KEY_F7 = 53,
	KEY_F8 = 54,
	KEY_F9 = 55,
	KEY_F10 = 56,
	KEY_F11 = 57,
	KEY_F12 = 58,
	//Keyboard control and other keys
	KEY_ESCAPE = 59,
	KEY_TILDE = 60,
	KEY_MINUS = 61,
	KEY_EQUALS = 62,
	KEY_BACKSPACE = 63,
	KEY_TAB = 64,
	KEY_OPENBRACE = 65,
	KEY_CLOSEBRACE = 66,
	KEY_ENTER = 67,
	KEY_SEMICOLON = 68,
	KEY_QUOTE = 69,
	KEY_BACKSLASH = 70,
	KEY_BACKSLASH2 = 71, /* DirectInput calls this DIK_OEM_102: "< > | on UK/Germany keyboards" */
	KEY_COMMA = 72,
	KEY_FULLSTOP = 73,
	KEY_SLASH = 74,
	KEY_SPACE = 75,

	KEY_INSERT = 76,
	KEY_DELETE = 77,
	KEY_HOME = 78,
	KEY_END = 79,
	KEY_PGUP = 80,
	KEY_PGDN = 81,
	KEY_LEFT = 82,
	KEY_RIGHT = 83,
	KEY_UP = 84,
	KEY_DOWN = 85,

	KEY_PAD_SLASH = 86,
	KEY_PAD_ASTERISK = 87,
	KEY_PAD_MINUS = 88,
	KEY_PAD_PLUS = 89,
	KEY_PAD_DELETE = 90,
	KEY_PAD_ENTER = 91,

	KEY_PRINTSCREEN = 92,
	KEY_PAUSE = 93,

	KEY_ABNT_C1 = 94,
	KEY_YEN = 95,
	KEY_KANA = 96,
	KEY_CONVERT = 97,
	KEY_NOCONVERT = 98,
	KEY_AT = 99,
	KEY_CIRCUMFLEX = 100,
	KEY_COLON2 = 101,
	KEY_KANJI = 102,

	KEY_PAD_EQUALS = 103,	/* MacOS X */
	KEY_BACKQUOTE = 104,	/* MacOS X */
	KEY_SEMICOLON2 = 105,	/* MacOS X -- TODO: ask lillo what this should be */
	KEY_COMMAND = 106,	/* MacOS X */

	KEY_BACK = 107,        /* Android back key */
	KEY_VOLUME_UP = 108,
	KEY_VOLUME_DOWN = 109,

	/* Android game keys */
	KEY_SEARCH = 110,
	KEY_DPAD_CENTER = 111,
	KEY_BUTTON_X = 112,
	KEY_BUTTON_Y = 113,
	KEY_DPAD_UP = 114,
	KEY_DPAD_DOWN = 115,
	KEY_DPAD_LEFT = 116,
	KEY_DPAD_RIGHT = 117,
	KEY_SELECT = 118,
	KEY_START = 119,
	KEY_BUTTON_L1 = 120,
	KEY_BUTTON_R1 = 121,
	KEY_BUTTON_L2 = 122,
	KEY_BUTTON_R2 = 123,
	KEY_BUTTON_A = 124,
	KEY_BUTTON_B = 125,
	KEY_THUMBL = 126,
	KEY_THUMBR = 127,

	KEY_UNKNOWN = 128,

	/* All codes up to before ALLEGRO_KEY_MODIFIERS can be freely
	* assignedas additional unknown keys, like various multimedia
	* and application keys keyboards may have.
	*/

	KEY_MODIFIERS = 215,

	KEY_LSHIFT = 215,
	KEY_RSHIFT = 216,
	KEY_LCTRL = 217,
	KEY_RCTRL = 218,
	KEY_ALT = 219,
	KEY_ALTGR = 220,
	KEY_LWIN = 221,
	KEY_RWIN = 222,
	KEY_MENU = 223,
	KEY_SCROLLLOCK = 224,
	KEY_NUMLOCK = 225,
	KEY_CAPSLOCK = 226,

	KEY_MAX
};
//Catches the state of the keyboard in that moment | PARAMETERS: Keyboard state.
void getKeyboard(ALLEGRO_KEYBOARD_STATE &keyState);
//Returns true if the specified key was pressed in the state | PARAMETERS: Keyboard state, Keycode.
bool keyPressed(ALLEGRO_KEYBOARD_STATE &keyState, keycodes key);

//MOUSE

#endif
