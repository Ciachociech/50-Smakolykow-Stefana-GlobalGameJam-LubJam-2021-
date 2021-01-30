#pragma once

#include "Graph.h"

class Stefan : public Graph
{
public:
	Stefan();
	Stefan(int x, int y);
	virtual ~Stefan();
private:
	int motivate;

};

