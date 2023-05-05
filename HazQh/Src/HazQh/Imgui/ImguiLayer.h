#pragma once
#include "../Layer.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"
#include "../Events/ApplicationEvent.h"

namespace HazQh
{
	class HAZQH_API ImguiLayer :public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach();
		void DeAttach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseMoveEvent(MouseMoveEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);

		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);
	private:
		float m_time;
	};
}