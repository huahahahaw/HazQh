#pragma once
#include "Core.h"
#include "Window.h"

namespace HazQh 
{
	class HAZQH_API Applicaiton
	{
	public:
		void Run();

		Applicaiton();
		virtual ~Applicaiton();

	private:
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
	};

	Applicaiton * CreateApplication();
}