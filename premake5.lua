workspace "HazQh"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = { }
IncludeDir["GLFW"] = "HazQh/vendor/GLFW/include"
IncludeDir["Glad"] = "HazQh/vendor/Glad/include"
IncludeDir["ImGui"] = "HazQh/vendor/imgui"

include "HazQh/vendor/GLFW"
include "HazQh/vendor/Glad"
include "HazQh/vendor/imgui"

project "HazQh"
    location "HazQh"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "HzPch.h"
    pchsource "HazQh/src/HzPch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "HAZQH_PLATFORM_WINDOWS",
            "HAZQH_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        optimize "On"
        runtime "Debug"
        defines
        {
            "HZ_ENABLE_ASSERTS",
        }

    filter "configurations:Release"
        defines "HZ_Release"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "HZ_Dist"
        symbols "On"
        runtime "Release"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "HazQh/vendor/spdlog/include",
        "HazQh/Src/"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"
        systemversion "latest"

    defines
    {
        "HAZQH_PLATFORM_WINDOWS",
    }

    links
    {
        "HazQh"
    }


    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines "HZ_Release"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "HZ_Dist"
        optimize "On"
        runtime "Release"