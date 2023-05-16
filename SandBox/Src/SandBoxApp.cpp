#include <HazQh.h>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}


class Examplelayer : public HazQh::Layer
{
public:
	Examplelayer()
		:Layer("Example")
	{
		auto cam = camera(5.0f, { 0.5f,0.5f });
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
	}
	~SandBox()
	{

	}


};

HazQh::Applicaiton* HazQh::CreateApplication()
{
	return new SandBox();
}

