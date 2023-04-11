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

		for (auto it = m_LayerStack.end();it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
			{
				break;
			}
		}

	}

	void Applicaiton::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Applicaiton::PushOverLayer(Layer* OverLayer)
	{
		m_LayerStack.PushOverLayer(OverLayer);
	}

	bool Applicaiton::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}

	void Applicaiton::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer:m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}
}
