#pragma once
#include "Platform/Windows/PltWindows.h"
#include "Renderer/Renderer.h"

//class Renderer;

int main(int argc, char** argv);

namespace Cndr
{

	class CR_API Application
	{ 
	public :
		Application();
		virtual ~Application();
		Window& GetWindow() { return *m_Window; }
		//void Close();
	private :
		void Run();
		// Event Function start
		//
		// Event Function End

	private :
		bool m_running = true;
		std::unique_ptr<PltWindows> m_Window;
		std::unique_ptr<Renderer> m_renderer;

		friend int ::main(int argc, char** argv);
	};


	// Defined in the client program
	Application* CreateApp();

}