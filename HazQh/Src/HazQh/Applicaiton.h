#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Layer.h"
#include "LayerStack.h"

namespace HazQh 
{
	class HAZQH_API Applicaiton
	{
	public:
		void Run();

		Applicaiton();
		virtual ~Applicaiton();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* OverLayer);

		bool OnWindowClose(WindowCloseEvent& event);

		inline static Applicaiton& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
	private:
		static Applicaiton* s_Instance;
	};

	Applicaiton * CreateApplication();
}