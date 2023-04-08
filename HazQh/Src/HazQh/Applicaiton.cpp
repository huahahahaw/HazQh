#include "HzPch.h"
#include "Applicaiton.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"


namespace HazQh
{
	Applicaiton::Applicaiton()
	{

	}

	Applicaiton::~Applicaiton()
	{

	}

	void Applicaiton::Run()
	{
		WindowResizeEvent e(1920,720);
		HZ_TRACE(e);

		while (true)
		{
			
		}
	}
}
