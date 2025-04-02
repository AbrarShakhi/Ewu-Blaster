
local GameName = "EwuBlaster"
local EngineName = "olcPixelGameEngine"

function download_gitsubmod()
	if(os.isdir(EngineName) == false) then
		print("Something Wrong with project setup. " .. EngineName .. " Folder not found.")
		print("Try to download from scrach.")
		print("You are in " .. os.getcwd())
		print("There should be a folder called " .. EngineName)
		os.exit(1)
	else
		os.chdir(EngineName)
		res = os.isfile("olcPixelGameEngine.h")
		os.chdir("..")
		
        if(not res) then
			cmd = "git submodule update --init --recursive"
			print("Executing '" .. cmd .. "'")
			os.execute(cmd)
		end
    end
end

function copy_assets()
	if(os.isdir("Assets") == false) then
		print("Assets folder not found. Creating one.")
		os.mkdir("Assets")
	end
	if(os.isdir("Assets/") == false) then
		print("Something Wrong with project setup. Assets Folder not found.")
		print("Try to download from scrach.")
		print("You are in " .. os.getcwd())
		print("There should be a folder called Assets")
		os.exit(1)
	else
		if(os.isdir(".out") == false) then
			print("Creating output directory.")
			os.mkdir(".out")
		elseif(os.isdir(".out/Assets") == true) then
			print("deleting Assets folder to output directory.")
			os.rmdir(".out/Assets")
		end
		print("Copying Assets folder to output directory.")
		os.mkdir(".out/Assets")
		os.execute("cp -r Assets/* .out/Assets/")
		-- os.execute("xcopy /E /I Assets .out/Assets")
		print("Assets folder copied to output directory.")
	end
end

download_gitsubmod()
copy_assets()

workspace("Ewu-Blaster")
	architecture("x64")
	configurations({ "Debug", "Release", "Dist" })
	startproject(GameName)
	language("C++")
	cppdialect("C++20")
	staticruntime("off")
	defines { "EWU_BLASTER" }

	targetname("%{prj.name}")
	targetdir(".out")
	objdir(".out/obj")

	filter("configurations:Debug")
		kind("ConsoleApp")
		defines({ "DEBUG" })
		runtime("Debug")
		symbols("On")

	filter("configurations:Release")
		-- kind("WindowedApp")
		kind("ConsoleApp")
		defines({ "RELEASE" })
		runtime("Release")
		optimize("On")
		symbols("On")

	filter("configurations:Dist")
		-- kind("WindowedApp")
		kind("ConsoleApp")
		defines({ "DIST" })
		runtime("Release")
		optimize("On")
		symbols("Off")

	filter { "system:windows" }
		links { "user32", "gdi32" }
		systemversion "latest"
		defines { "WINDOWS" }

	filter { "action:vs*" }
		buildoptions { "/EHsc", "/MP", "/Zc:preprocessor", "/Zc:__cplusplus" }
		defines { "MSVC" }

	filter { "action:gmake*"}
		buildoptions { "-std=c++20"}
		defines { "GCC" }

	filter { "system:linux" }
		links { "X11", "GL", "pthread", "png" }
		defines {
			"_GLIBCXX_USE_CXX11_ABI=0",
			 "LINUX"
		}

	filter { "system:macosx" }
		defines { "MACOSX" }
	filter {}



project(GameName)
	files {
		EngineName .. "/*.h",
		GameName .. "/includes/**.h",
		GameName .. "/src/**.cpp"
	}
	includedirs {
		EngineName .. "/",
		GameName .. "/includes/"
	}
