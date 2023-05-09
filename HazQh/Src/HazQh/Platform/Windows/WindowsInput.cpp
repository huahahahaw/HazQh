#include "HzPch.h"
#include "WindowsInput.h"
#include "HazQh/Applicaiton.h"
#include <GLFW/glfw3.h>
#include "WindowsWindow.h"

namespace HazQh
{
	Input* Input::s_Instance = new WindowsInput;

	bool WindowsInput::IsKeyPressedImp(int keycode)
	{
		GLFWwindow* mWindows = static_cast<GLFWwindow*>(Applicaiton::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(mWindows, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMousePressedImp(int button)
	{
		GLFWwindow* mWindows = static_cast<GLFWwindow*>(Applicaiton::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(mWindows, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetCursorPosImp()
	{
		GLFWwindow* mWindows =static_cast<GLFWwindow*>( Applicaiton::Get().GetWindow().GetNativeWindow());
		double XPos, YPos;
		glfwGetCursorPos(mWindows, &XPos, &YPos);
		return {(float)XPos,(float)YPos};
	}

	float WindowsInput::GetMouseXImp()
	{
		auto[x,y] = GetCursorPosImp();
		return x;
	}

	float WindowsInput::GetMouseYImp()
	{
		auto [x, y] = GetCursorPosImp();
		return y;
	}

}
