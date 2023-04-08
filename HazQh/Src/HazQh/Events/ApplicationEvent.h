#pragma once

#include "Event.h"


namespace HazQh
{
	class HAZQH_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int InWidth, unsigned int  InHeigh)
			:m_Width(InWidth), m_Height(InHeigh){ }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
			return ss.str();

		}

	private:
		unsigned int m_Width, m_Height;
	};
}