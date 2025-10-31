#include "lepch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace le {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LE_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LE_TRACE(e.ToString());
		}

		while (true);
	}
}