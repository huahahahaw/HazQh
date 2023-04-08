#pragma once

#include "Event.h"

namespace HazQh
{
	class HAZQH_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			:m_keyCode(keycode) {}

		int m_keyCode;
	};

	/*class HAZQH_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			:
	};
	*/
}