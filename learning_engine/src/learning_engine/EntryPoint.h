#pragma once

#ifdef LE_PLATFORM_WINDOWS

extern le::Application* le::CreateApplication();

int main(int argc, char** argv) {

	printf("Engine started");

	auto app = le::CreateApplication();
	app->Run();
	delete app;

}

#endif // LE_PLATFORM_WINDOWS

