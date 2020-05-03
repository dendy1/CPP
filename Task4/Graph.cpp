#include "pch.h"
#include "Graph.h"

void Graph::_markNeighbors(std::vector<Vertex*> marked, Vertex* currentVertex, int layer)
{
	if (marked.size() == vertices.size())
		return;

	for (auto vertex : currentVertex->neighbors)
	{
		if (std::find(marked.begin(), marked.end(), vertex) != marked.end())
			continue;

		vertex->layer = layer;
		marked.push_back(vertex);
	}

	for (auto vertex : currentVertex->neighbors)
	{
		_markNeighbors(marked, vertex, layer + 1);
	}
}

Graph::Graph()
{
	vertices = std::vector<Vertex*>();
}

Graph::Graph(std::vector<Vertex*> vertices)
{
	vertices = vertices;
}

Graph::~Graph()
{
	for (auto vertex : vertices)
	{
		delete[] vertex;
	}
}

void Graph::MarkNeighbors(int index)
{
	Vertex* currentVertex = vertices[index];
	currentVertex->layer = 0;
	_markNeighbors(std::vector<Vertex*> { currentVertex }, currentVertex, 1);
}
