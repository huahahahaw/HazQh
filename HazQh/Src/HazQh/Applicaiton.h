#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace HazQh 
{
	class HAZQH_API Applicaiton
	{
	public:
		void Run();

		Applicaiton();
		virtual ~Applicaiton();

		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& event);
	private:
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
	};

	Applicaiton * CreateApplication();
}