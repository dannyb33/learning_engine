#include "sbpch.h"
#include <LE.h>

class Sandbox : public le::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}

}; 

le::Application* le::CreateApplication() {
	return new Sandbox();
}