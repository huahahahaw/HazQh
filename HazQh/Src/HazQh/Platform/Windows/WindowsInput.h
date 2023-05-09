#pragma once
#include "HazQh/Input.h"

namespace HazQh
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImp(int keycode) override;

		virtual bool IsMousePressedImp(int button) override;

		virtual std::pair<float, float> GetCursorPosImp() override;
		virtual float GetMouseXImp() override;
		virtual float GetMouseYImp() override;

	};

}

