#pragma once

#include "Cndr/Core.h"
#include "string"
namespace Cndr
{
	// Windows Instance Class 
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& str = "Cndr Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(str), Width(width), Height(height)
		{

		}

	};

	class CR_API Window
	{
	public :
		virtual ~Window() {} ;

		virtual void OnUpdate() = 0;
		virtual unsigned int Get_Width() const = 0;
		virtual unsigned int Get_Height() const = 0;

		// Window Attributes

		virtual void Set_VSync(bool value) = 0;
		virtual bool Is_VSync() const = 0;

		// Window Properties Function
		static Window* Create(const WindowProperties& prop = WindowProperties());
	};

}