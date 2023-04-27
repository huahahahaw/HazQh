#pragma once
#include "../Layer.h"

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
		float m_time;
	};
}