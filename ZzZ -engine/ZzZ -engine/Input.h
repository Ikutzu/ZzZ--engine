#pragma once
#include <windows.h>
#include "debugger.h"

namespace ZZZ
{
	enum Key
	{
		Unknown = -1, // Unhandled key
		A = 0,        // A key
		B,            // B key
		C,            // C key
		D,            // D key
		E,            // E key
		F,            // F key
		G,            // G key
		H,            // H key
		I,            // I key
		J,            // J key
		K,            // K key
		L,            // L key
		M,            // M key
		N,            // N key
		O,            // O key
		P,            // P key
		Q,            // Q key
		R,            // R key
		S,            // S key
		T,            // T key
		U,            // U key
		V,            // V key
		W,            // W key
		X,            // X key
		Y,            // Y key
		Z,            // Z key
		Num0,         // 0 key
		Num1,         // 1 key
		Num2,         // 2 key
		Num3,         // 3 key
		Num4,         // 4 key
		Num5,         // 5 key
		Num6,         // 6 key
		Num7,         // 7 key
		Num8,         // 8 key
		Num9,         // 9 key
		Escape,    // Escape key
		LControl,     // left Control key
		LShift,       // left Shift key
		LAlt,         // left Alt key
		LSystem,      // left OS specific key
		RControl,     // right Control key
		RShift,       // right Shift key
		RAlt,         // right Alt key
		RSystem,      // right OS specific key
		Menu,         // Menu key
		LBracket,     // [ key
		RBracket,     // ] key
		SemiColon,    // ; key
		Comma,        // , key
		Period,       // . key
		Quote,        // ' key
		Slash,        // / key
		BackSlash,    // \ key
		Tilde,        // ~ key
		Equal,        // = key
		Dash,         // - key
		Space,        // Space key
		Return,       // Return key
		BackSpace,    // Backspace key
		Tab,          // Tabulation key
		PageUp,       // Page up key
		PageDown,     // Page down key
		End,          // End key
		Home,         // Home key
		Insert,       // Insert key
		Delete,       // Delete key
		Add,          // + key
		Subtract,     // - key
		Multiply,     // * key
		Divide,       // / key
		Left,         // Left arrow
		Right,        // Right arrow
		Up,           // Up arrow
		Down,         // Down arrow
		Numpad0,      // numpad 0 key
		Numpad1,      // numpad 1 key
		Numpad2,      // numpad 2 key
		Numpad3,      // numpad 3 key
		Numpad4,      // numpad 4 key
		Numpad5,      // numpad 5 key
		Numpad6,      // numpad 6 key
		Numpad7,      // numpad 7 key
		Numpad8,      // numpad 8 key
		Numpad9,      // numpad 9 key
		F1,           // F1 key
		F2,           // F2 key
		F3,           // F3 key
		F4,           // F4 key
		F5,           // F5 key
		F6,           // F6 key
		F7,           // F7 key
		F8,           // F8 key
		F9,           // F9 key
		F10,          // F10 key
		F11,          // F11 key
		F12,          // F12 key
		F13,          // F13 key
		F14,          // F14 key
		F15,          // F15 key
		Pause,        // Pause key

		//mouse
		MouseLeft,
		MouseRight,
		MouseMiddle,
		Mouse4,
		Mouse5,

		KeyCount
	};

	class Input
	{
	public:
		bool initialize(HWND* windowHandle);
		void update();
		bool isKeyDown(Key key);
		bool isKeyPressed(Key key);
		POINT getCursorPos(bool asScreenCoordinates = false);

	private:
		HWND* hWnd;
		bool lastState[KeyCount];
		POINT cursorWindowPos;
		POINT cursorScreenPos;
	};
}

