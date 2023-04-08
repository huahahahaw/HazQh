#pragma once
#include "HzPch.h"

#include "Core.h"

namespace HazQh
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "HazQh Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	class HAZQH_API Window
	{
	public:
	
		virtual ~Window(){ }

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		//virtual void SetEventCallback(const EventCallbackFn)
		virtual void SetVSync(bool enabled) = 0;
		virtual void IsVsync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}
