#pragma once

#include "Event.h"


namespace HazQh
{
	class HAZQH_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(double XPos, double YPos)
			:m_XPos(XPos), m_YPos(YPos) { }

		inline double GetXPos() const { return m_XPos; }
		inline double GetYPos() const { return m_YPos; }

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

			std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved: " << m_XPos << "," << m_YPos;
			return ss.str();
		}

	private:
		double m_XPos, m_YPos;
	};

	class HAZQH_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(double Xoffset, double Yoffset)
			:m_Xoffset(Xoffset), m_Yoffset(Yoffset) { }

		inline double GetXoffset() const { return m_Xoffset; }
		inline double GetYoffset() const { return m_Yoffset; }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

			std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_Xoffset << "," << m_Yoffset;
			return ss.str();
		}

	private:
		double m_Xoffset, m_Yoffset;
	};

	class HAZQH_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
	protected:
		MouseButtonEvent(int Button)
			:m_Button(Button) {}

		int m_Button;
	};

	class HAZQH_API MouseButtonPressedEvent :public MouseButtonEvent

	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button){ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button ;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZQH_API MouseButtonReleasedEvent :public MouseButtonEvent

	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
