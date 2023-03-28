#include <HazQh.h>

class SandBox :public HazQh::Applicaiton
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}


};

HazQh::Applicaiton* HazQh::CreateApplication()
{
	return new SandBox();
}

