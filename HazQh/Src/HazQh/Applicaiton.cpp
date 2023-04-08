#include "HzPch.h"
#include "Applicaiton.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <gl/GL.h>


namespace HazQh
{
	Applicaiton::Applicaiton()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Applicaiton::~Applicaiton()
	{

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
