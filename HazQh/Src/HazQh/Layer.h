#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace HazQh
{
	class HAZQH_API  Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDeAttach();
		virtual void OnUpdate();
		virtual void OnImGuiRender();
		virtual void OnEvent(Event& event) { }


		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}


