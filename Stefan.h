#pragma once

#include "Graph.h"

class Stefan : public Graph
{
public:
	Stefan();
	Stefan(int x, int y);
	virtual ~Stefan();

	void setConfusion(bool value);
	bool getConfusion();
private:
	int motivate;
	bool confuseEffect;
};

