-- premake5.lua

workspace "GdEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release"
	}

	startproject "Edtr"

	flags{
		"MultiProcessorCompile",
		"FloatFast"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GdEngine"
	
	location "GdEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/Vendor/spdlog/include",
		"%{prj.name}/src/Interface",
		"%{prj.name}/src"
	}
	
	pchheader "Cndrpch.h"
	pchsource "%{prj.name}/src/Cndrpch.cpp"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"CR_PLATFORM_WINDOWS"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Edtr")
		}
	
	filter "configurations:Debug"
		defines "CR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CR_RELEASE"
		optimize "On"

project "Edtr"

	location "Edtr"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	dim = "%{prj.name}"

	includedirs{
		"GdEngine/Vendor/spdlog/include",
		"GdEngine/src"
	}

	links{
		"GdEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"CR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CR_RELEASE"
		optimize "On"
