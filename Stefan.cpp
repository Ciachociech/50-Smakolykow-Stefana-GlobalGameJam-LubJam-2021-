#include "Stefan.h"

Stefan::Stefan() : Graph(), motivate(-1), confuseEffect(false) {}

Stefan::Stefan(int x, int y) : Graph(x, y), motivate(-1), confuseEffect(false) {}

Stefan::~Stefan() { Graph::~Graph(); }

void Stefan::setConfusion(bool value) { confuseEffect = value; }

bool Stefan::getConfusion() { return confuseEffect; }
