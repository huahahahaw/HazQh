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

		virtual void OnAttach() override;
		virtual void OnDeAttach() override;
		void OnEvent(Event& event) override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_time;
	};
}