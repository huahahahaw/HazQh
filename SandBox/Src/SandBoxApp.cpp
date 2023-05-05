#include <HazQh.h>

class Examplelayer : public HazQh::Layer
{
public:
	Examplelayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		HZ_INFO("Examplelayer:Update");
	}

	void OnEvent(HazQh::Event& event) override
	{
		HZ_TRACE("Examplelayer:OnEvent : {0}", event);
	}
};

class SandBox :public HazQh::Applicaiton
{
public:
	SandBox()
	{
		//PushLayer(new Examplelayer());
		PushOverLayer(new HazQh::ImguiLayer());
	}
	~SandBox()
	{

	}


};

HazQh::Applicaiton* HazQh::CreateApplication()
{
	return new SandBox();
}

