#pragma once
#include "RenderBatch.h"

class World : public RenderBatch {
public:
	static World* Default();
	void Tick(double deltaTime);
	virtual void Render() override;
};