#include "Application.h"

namespace Cndr
{
	Application::Application()
	{

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		// ---- Contains Trigger files to run the application 

		// Example the DirectX api Init, Update, Delete funtions
		while (m_running)
		{
			m_Window->Create();
		}
	}

}