#pragma once
#include "Core.h"

namespace HazQh 
{
	class HAZQH_API Applicaiton
	{
	public:
		void Run();

		Applicaiton();
		virtual ~Applicaiton();
	};

	Applicaiton * CreateApplication();
}