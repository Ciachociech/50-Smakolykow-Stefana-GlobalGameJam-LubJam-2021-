#include "Stefan.h"

Stefan::Stefan() : Graph(), motivate(-1) {}

Stefan::Stefan(int x, int y) : Graph(x, y), motivate(-1) {}

Stefan::~Stefan() { Graph::~Graph(); }
