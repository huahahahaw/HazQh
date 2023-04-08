#pragma once
#include "HazQh/Window.h"
#include "GLFW/glfw3.h"

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


		void IsVsync() const override;

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
		};

		WindowDate m_Data;

		
	};
}