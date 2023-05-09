#pragma once

namespace HazQh
{
	class Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImp(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMousePressedImp(button); }
	
		inline static std::pair<float, float> GetCursorPos() { return s_Instance->GetCursorPosImp(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImp(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImp(); }
	protected:
		virtual bool IsKeyPressedImp(int keycode) = 0;

		virtual bool IsMousePressedImp(int button) = 0;

		virtual std::pair<float, float> GetCursorPosImp() = 0;
		virtual float GetMouseXImp() = 0;
		virtual float GetMouseYImp() = 0;
	private:
		static Input* s_Instance;

	};

};