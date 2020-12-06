
#include "CndrInclude.h"

class Client : public Cndr::Application
{
public:
	Client()
	{

	}
	~Client()
	{

	}
};


Cndr::Application* Cndr::CreateApp()
{
	return new Client();
}