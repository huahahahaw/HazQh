#include "HzPch.h"
#include "Applicaiton.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <gl/GL.h>


namespace HazQh
{
#define BIND_EVENT_FN(x) std::bind(&Applicaiton::x, this, std::placeholders::_1)

	Applicaiton::Applicaiton()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Applicaiton::OnEvent));
	}

	Applicaiton::~Applicaiton()
	{

	}

	void Applicaiton::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		HZ_CORE_INFO("{0}",e);

	}

	bool Applicaiton::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}

	void Applicaiton::Run()
	{
		WindowResizeEvent e(1920,720);
		HZ_TRACE(e);

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
