#pragma once

#ifdef LE_PLATFORM_WINDOWS

extern le::Application* le::CreateApplication();

int main(int argc, char** argv) {

	le::Log::Init();
	LE_CORE_WARN("Initialized Log!");
	int a = 5;
	LE_INFO("Started! Var={0}", a);

	auto app = le::CreateApplication();
	app->Run();
	delete app;

}

#endif // LE_PLATFORM_WINDOWS

