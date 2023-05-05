#pragma once
#include "HazQh/Window.h"

struct GLFWwindow;

namespace HazQh
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;


		inline unsigned int GetWidth() const override { return m_Data.Width; };


		inline unsigned int GetHeight() const override { return m_Data.Height; };


		void SetVSync(bool enabled) override;


		bool IsVsync() const override;


		void SetEventCallback(const EventCallbackFn) override;

		inline GLFWwindow* GetGLFWwindow() { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowDate
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowDate m_Data;

		
	};
}