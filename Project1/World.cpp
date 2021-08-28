#include "World.h"

World* World::Default()
{
	return nullptr;
}

void World::Tick(double deltaTime)
{
}

void World::Render()
{
	RenderBatch::Render();
}
