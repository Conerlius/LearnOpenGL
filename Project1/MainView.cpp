#include "MainView.h"
#include "Application.h"
#include "CourseManager.h"

MainView::MainView(std::string courseIndex)
{
	CourseIndex = courseIndex;
}

void MainView::Tick(double deltaTime)
{
	Application::Instance()->AddViewToViewPort(CourseManager::CreateCourse(CourseIndex));
	Application::Instance()->RemoveViewFromViewPort(this);
}
