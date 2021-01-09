#pragma once

#include "../Platform.h"
#include "Cndr/Log.h"
#include "Cndr/Core.h"
//#include "Cndr/Application.h"

namespace Cndr
{

	class PltWindows : public Cndr::Window
	{
	public :
		PltWindows(const WindowProperties& props);
		virtual ~PltWindows();
		
		// Inherited via Window
		inline unsigned int Get_Width() const override { return m_Data.Width; }
		virtual unsigned int Get_Height() const override { return m_Data.Height; }
		virtual void Set_VSync(bool value) override;
		virtual bool Is_VSync() const override;

		virtual bool Init(const WindowProperties& props);
		void OnUpdate() override;
		bool broadcast();
		virtual void Shutdown();

	private :
		
		HWND m_hwnd;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
		};

		WindowData m_Data;

	protected :

		bool IsVSync;
		//friend class Application;

	};

}