#pragma once

#include "Platform.h"
#include "Cndr/Log.h"
#include "Cndr/Core.h"

namespace Cndr
{

	class CR_API PltWindows : public Cndr::Window
	{
	public :
		PltWindows(const WindowProperties& props);
		virtual ~PltWindows();
		void OnUpdate() override;

		// Inherited via Window
		inline unsigned int Get_Width() const override { return m_Data.Width; }

		virtual unsigned int Get_Height() const override { return m_Data.Height; }

		virtual void Set_VSync(bool value) override;
		virtual bool Is_VSync() const override;
		virtual bool Init(const WindowProperties& props);
		bool broadcast();
		virtual void Shutdown();
		static LRESULT CALLBACK windowProc(HWND hwnd, UINT   msg, WPARAM wParam, LPARAM lParam);

	private :
		HWND m_hwnd;
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
		};
		bool VSync=false;

		WindowData m_Data;

	};

}