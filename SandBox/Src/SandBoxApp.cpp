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
		if (HazQh::Input::IsKeyPressed(HZ_KEY_SPACE))
		{
			HZ_TRACE("Space Key is Pressed!");
		}
		
	}

	void OnEvent(HazQh::Event& event) override
	{
		if (event.GetEventType() == HazQh::EventType::KeyPressed)
		{
			HazQh::KeyPressedEvent& e = (HazQh::KeyPressedEvent&)event;
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
		if (event.GetEventType() == HazQh::EventType::MouseButtonPressed)
		{
			HazQh::MouseButtonEvent& e = (HazQh::MouseButtonEvent&)event;
			HZ_TRACE("{0}", (char)e.GetMouseButton());
		}
	}
};

class SandBox :public HazQh::Applicaiton
{
public:
	SandBox()
	{
		PushLayer(new Examplelayer());
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

