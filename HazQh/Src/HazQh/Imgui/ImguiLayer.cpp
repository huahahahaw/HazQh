#include "HzPch.h"
#include "ImguiLayer.h"
#include "imgui.h"
#include "../Platform/OpenGL/imgui_impl_opengl3.h"
#include "../Applicaiton.h"
#include "examples/libs/glfw/include/GLFW/glfw3.h"
#include "../Platform/OpenGL/imgui_impl_glfw.h"
#include "../Platform/Windows/WindowsWindow.h"

namespace HazQh
{	
#define IMGUI_BIND_EVENT_FN(x) std::bind(&ImguiLayer::x,this, std::placeholders::_1)

	ImguiLayer::ImguiLayer()
		:Layer("ImguiLayer")
	{

	}

	ImguiLayer::~ImguiLayer()
	{

	}

	void ImguiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		//io.SetClipboardTextFn = ImGui_ImplGlfw_SetClip
		ImGui_ImplOpenGL3_Init("#version 410 core");
		/*
		Applicaiton& app = Applicaiton::Get();
		WindowsWindow* window = dynamic_cast<WindowsWindow*>(&app.GetWindow());
		if (window != nullptr)
			ImGui_ImplGlfw_InitForOpenGL(window->GetGLFWwindow(), true);
		*/
	}

	void ImguiLayer::DeAttach()
	{

	}

	void ImguiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Applicaiton& app = Applicaiton::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
		m_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispacter(event);
		dispacter.Dispatch<MouseMoveEvent>(IMGUI_BIND_EVENT_FN(OnMouseMoveEvent));
		dispacter.Dispatch<MouseScrolledEvent>(IMGUI_BIND_EVENT_FN(OnMouseScrolledEvent));
		dispacter.Dispatch<MouseButtonPressedEvent>(IMGUI_BIND_EVENT_FN(OnMouseButtonPressedEvent));
		dispacter.Dispatch<MouseButtonReleasedEvent>(IMGUI_BIND_EVENT_FN(OnMouseButtonReleasedEvent));

		dispacter.Dispatch<KeyPressedEvent>(IMGUI_BIND_EVENT_FN(OnKeyPressedEvent));
		dispacter.Dispatch<KeyReleasedEvent>(IMGUI_BIND_EVENT_FN(OnKeyReleasedEvent));
		dispacter.Dispatch<KeyTypedEvent>(IMGUI_BIND_EVENT_FN(OnKeyTypedEvent));
		

		dispacter.Dispatch<WindowResizeEvent>(IMGUI_BIND_EVENT_FN(OnWindowResizeEvent));

	}

	bool ImguiLayer::OnMouseMoveEvent(MouseMoveEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetXPos(),e.GetYPos());

		return false;
	}

	bool ImguiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXoffset();
		io.MouseWheel += e.GetYoffset();

		return false;
	}

	bool ImguiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImguiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImguiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImguiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		return false;
	}

	bool ImguiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
		{
			io.AddInputCharacter((unsigned short)keycode);
		}

		return false;
	}

	bool ImguiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}

}