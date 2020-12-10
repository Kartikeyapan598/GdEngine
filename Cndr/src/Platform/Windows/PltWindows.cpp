#include "PltWindows.h"

namespace Cndr
{
	static bool Window_init;

	LRESULT CALLBACK windowProc(
		HWND   hwnd    // Window Handle (Window object)
		, UINT   msg     // Window Message  
		, WPARAM wParam  // Additional message information
		, LPARAM lParam  // Additional message information
	) {

		// Process messages 
		switch (msg)
		{
		case WM_CREATE :
			break;
		case WM_CLOSE :
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY :
			PostQuitMessage(0);
			break;
		case WM_MOVE :
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}

		return 0;
	}

	Window* Window::Create(const WindowProperties& props)
	{
		return new PltWindows(props);
	}
	
	PltWindows::PltWindows(const WindowProperties& props)
	{
		Init(props);
	}

	PltWindows::~PltWindows()
	{
		//Shutdown();
	}

	void PltWindows::OnUpdate()
	{

	}

	void PltWindows::Shutdown()
	{
		DestroyWindow(m_hwnd);
	}

	void PltWindows::Set_VSync(bool value)
	{
		IsVSync = value;
	}

	bool PltWindows::Is_VSync() const
	{
		return IsVSync;
	}

	bool PltWindows::Init(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CR_CORE_INFO("Window creation for dim- {0} {1} {2}", props.Title,props.Width,props.Height);

		if (!Window_init)
		{
			CR_CORE_INFO("Window_init is set to true \n");
			Window_init = true;
		}

		WNDCLASSEX wc;
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW + 2;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;
		wc.lpszClassName = "MyWindowClass";
		wc.lpszMenuName = "";
		wc.style = NULL;
		wc.lpfnWndProc = &windowProc;

		if (!::RegisterClassEx(&wc)) // If the registration of class will fail, the function will return false
			return false;

		CR_CORE_INFO("Window Creation");

		m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", m_Data.Title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, m_Data.Width, m_Data.Height,
			NULL, NULL, NULL, this);

		//if the creation fail return false
		if (!m_hwnd)
		{
			CR_CORE_ERROR("m_hwnd value error");
			return false;
		}

		ShowWindow(m_hwnd, SW_SHOW);
		UpdateWindow(m_hwnd);

		return true;
	}

	bool PltWindows::broadcast()
	{
		MSG msg = { 0 };

		BOOL bRet = 1;
		CR_CORE_INFO("Flag in Broadcast");
		while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0)
		{
			if (bRet == -1)
			{
				MessageBox(0, "GetMessage FAILED", "Error", MB_OK);
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		OnUpdate();

		return 0;//(int)msg.wParam;
	}
	
}