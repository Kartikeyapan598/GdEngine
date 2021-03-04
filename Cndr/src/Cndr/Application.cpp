#include "Cndrpch.h"	
#include "Application.h"

namespace Cndr
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{
		//m_renderer->Clear();
	}

	void Application::Run()
	{
		// ---- Contains Trigger files to run the application 

		// Example the DirectX api Init, Update, Delete funtions

		/*
		m_Window->Create();
		m_renderer->GetRenderer();
		*/
		m_Window->Create();
		//m_renderer->GetRenderer();
		//m_renderer->Init();
		while (m_running)
		{
			m_Window->broadcast();
			//m_Window->OnUpdate();
		}
		//m_renderer->Clear();
	}

}