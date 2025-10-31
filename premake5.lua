workspace "learning_engine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "learning_engine/vendor/GLFW/include"

include "learning_engine/vendor/GLFW"

project "learning_engine"
    location "learning_engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "lepch.h"
    pchsource "learning_engine/src/lepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
    }

    links
    {
        "GLFW",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LE_PLATFORM_WINDOWS",
            "LE_BUILD_DLL"
        }

        buildoptions { "/utf-8" }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "LE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "LE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sbpch.h"
    pchsource "Sandbox/src/sbpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "learning_engine/vendor/spdlog/include",
        "learning_engine/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LE_PLATFORM_WINDOWS"
        }

        buildoptions { "/utf-8" }

        links
        {
            "learning_engine"
        }

    filter "configurations:Debug"
        defines "LE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "LE_DIST"
        optimize "On"
