local GameName = "Space-Blaster"

workspace(GameName)
	architecture("x64")
	configurations({ "Debug", "Release", "Dist" })
	startproject(GameName)
	language("C++")
	cppdialect("C++20")
	staticruntime("off")
	defines { "SPACE_BLASTER" }
	
	targetname("%{prj.name}")
	targetdir(".out")
	objdir(".out/obj")
	
	filter("configurations:Debug")
		kind("ConsoleApp")
		defines({ "DEBUG" })
		runtime("Debug")
		symbols("On")
		
	filter("configurations:Release")
		kind("WindowedApp")
		defines({ "RELEASE" })
		runtime("Release")
		optimize("On")
		symbols("On")
		
	filter("configurations:Dist")
		kind("WindowedApp")
		defines({ "DIST" })
		runtime("Release")
		optimize("On")
		symbols("Off")

	filter { "system:windows" }
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
		links { "user32", "gdi32" }
		systemversion "latest"
		defines { "WINDOWS" }
		
	filter { "system:linux" }
		buildoptions { "-std=c++20" }
		links { "X11", "GL", "pthread", "png" }
		defines { 
			"_GLIBCXX_USE_CXX11_ABI=0",
			 "LINUX"
		}
		
	filter { "system:macosx" }
		defines { "MACOSX" }
	filter {}


project(GameName)
	files({
		"Space-Blaster/src/**.cpp",
	})
	includedirs({
		"Core/olcPixelGameEngine",
		"Space-Blaster/includes",
	})
