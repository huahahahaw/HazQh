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

include "HazQh/vendor/GLFW"

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
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
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
        buildoptions "/MDd"
        defines
        {
            "HZ_ENABLE_ASSERTS",
        }

    filter "configurations:Release"
        defines "HZ_Release"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "HZ_Dist"
        symbols "On"
        buildoptions "/MD"

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
        staticruntime "On"
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
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "HZ_Release"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "HZ_Dist"
        optimize "On"
        buildoptions "/MD"