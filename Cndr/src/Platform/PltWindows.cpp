#include "PltWindows.h"

namespace Cndr
{
	static bool Window_init;

	LRESULT CALLBACK PltWindows::windowProc(
		HWND   hwnd    // Window Handle (Window object)
		, UINT   msg     // Window Message  
		, WPARAM wParam  // Additional message information
		, LPARAM lParam	)	// Additional message information 
	{

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
		return /*nullptr;*/new PltWindows(props);
	}
	
	PltWindows::PltWindows(const WindowProperties& props)
	{
		Init(props);
	}

	PltWindows::~PltWindows()
	{
		Shutdown();
		Window_init = false;
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
		VSync = value;
	}

	bool PltWindows::Is_VSync() const
	{
		return VSync;
	}

	bool PltWindows::Init(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CR_CORE_INFO("Window creation for dim- {0} {1} {2}", props.Title,props.Width,props.Height);

		if (!Window_init)
		{
			Window_init = true;
		}
		//WNDCLASSEX wc;
		//wc.lpszClassName = "Cndr";
		//wc.lpfnWndProc = &windowProc;
		//wc.cbSize = sizeof(WNDCLASSEX);
		//wc.style = 0;
		//wc.cbClsExtra = 0;
		//wc.hInstance = NULL; // Recheck
		//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		//wc.hCursor = LoadCursor(NULL, IDI_APPLICATION);
		//wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);   // (HBRUSH) CreateSolidBrush(RGB(10, 20, 30)); //
		//wc.lpszMenuName = NULL;
		//wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		
		WNDCLASSEX wc;
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;
		wc.lpszClassName = "MyWindowClass";
		wc.lpszMenuName = "";
		wc.style = NULL;


		if (RegisterClassEx(&wc)== NULL)
		{
			CR_CORE_ERROR("Window Registration Failed");
			return false;
		}

		m_hwnd = CreateWindowExA(WS_OVERLAPPEDWINDOW,
			wc.lpszClassName,
			m_Data.Title.c_str(), // c_str is funtion to convert std::string to LPSTR
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			m_Data.Width,
			m_Data.Height,
			NULL,
			NULL,
			NULL,
			NULL);

		if (m_hwnd == NULL)
		{
			CR_CORE_ERROR("HWND Creation Failed");
			return - 1;
		}

		ShowWindow(m_hwnd, SW_SHOW);
		UpdateWindow(m_hwnd);

		//flag to show window is initialized
		Window_init = true;

		return true;
	}

	bool PltWindows::broadcast()
	{
		MSG msg;


		while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep(1);

		return true;
	}
	
}