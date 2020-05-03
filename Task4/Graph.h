#pragma once
#include "Vertex.h"

class Graph
{
private:
	void Graph::_markNeighbors(std::vector<Vertex*> marked, Vertex* currentVertex, int layer);
public:
	std::vector<Vertex*> vertices;

	Graph();
	Graph(std::vector<Vertex*> vertices);
	~Graph();

	void Graph::MarkNeighbors(int index);
};

