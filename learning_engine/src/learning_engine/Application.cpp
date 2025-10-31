#include "lepch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Log.h"

namespace le {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		KeyPressedEvent k(6, 7);
		if (k.IsInCategory(EventCategoryApplication))
		{
			LE_TRACE(k.ToString());
		}
		if (k.IsInCategory(EventCategoryInput))
		{
			LE_TRACE(k.ToString());
		}

		while (true);
	}
}