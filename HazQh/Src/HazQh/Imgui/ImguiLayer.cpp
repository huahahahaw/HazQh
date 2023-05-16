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
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		/*io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;*/

		ImGui::StyleColorsDark();

		/*ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}*/

		Applicaiton& app = Applicaiton::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 430");
	}

	void ImguiLayer::OnDeAttach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImguiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void ImguiLayer::Begin()
	{
		ImGui_ImplGlfw_NewFrame();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
	}

	void ImguiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		Applicaiton& app = Applicaiton::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		/*if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)ImGuiWindowFlags
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}*/

	}

	void ImguiLayer::OnEvent(Event& event)
	{
		
	}

}