#include "Course1.h"
#include <glad\glad.h>
#include "../Base/VertexItem.h"

COURSE_CLASS(Course1)

Course1::Course1()
{
	auto item = new VertexItem();
	this->AddRenderItem(item);
	std::vector<float> vs = {
		-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
	};
	item->SetVertices(vs);

	
}

Course1::~Course1()
{
}

void Course1::Tick(double deltaTime)
{
}
