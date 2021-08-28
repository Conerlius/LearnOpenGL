#include "MainView.h"
#include "Application.h"
#include "CourseManager.h"

MainView::MainView()
{
	
}

void MainView::Tick(double deltaTime)
{
	Application::Instance()->AddViewToViewPort(CourseManager::CreateCourse("Course1"));
	Application::Instance()->RemoveViewFromViewPort(this);
}
