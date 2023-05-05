#include "HzPch.h"
#include "WindowsWindow.h"
#include "HazQh/Events/ApplicationEvent.h"
#include "HazQh/Events/MouseEvent.h"
#include "HazQh/Events/KeyEvent.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

namespace HazQh
{
	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int error_code, const char* description)
	{
		HZ_CORE_ERROR("GLFWErrorCallback : ({0}),{1}", error_code, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVsync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn EventCallback)
	{
		m_Data.EventCallback = EventCallback;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HZ_CORE_INFO("Creating window {0} ({1} , {2}) ", props.Title, props.Width, props.Height);
		if (!s_GLFWInitialized)
		{
			bool success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Faild to initailize Glad!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);

			MouseMoveEvent event(xpos, ypos);
			data.EventCallback(event);
			});
			

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);
			
			MouseScrolledEvent event(xoffset,yoffset);
			data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);
			
			switch (action)
			{
					//`GLFW_PRESS`, `GLFW_RELEASE` or `GLFW_REPEAT`
				case GLFW_PRESS:
				{
					KeyPressedEvent evnet(key, 0);
					data.EventCallback(evnet);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent evnet(key, 1);
					data.EventCallback(evnet);
					break;
				}
			}
			
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keyCode){
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(keyCode);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowDate& data = *(WindowDate*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
			
			});
			
	}

	void HazQh::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
