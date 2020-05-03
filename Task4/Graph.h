#pragma once
#include "Vertex.h"
#include <vector>
#include <queue>
#include <string>

template <class T>
class Graph
{
public:
	std::vector<Vertex<T>*> vertices;

	Graph()
	{
		vertices = std::vector<Vertex<T>*>();
	};

	Graph(std::vector<Vertex<T>*> vertices)
	{
		this->vertices = vertices;
	};
	
	~Graph() 
	{
		for (auto vertex : vertices)
		{
			delete[] vertex;
		}
	};

	void MarkNeighbors(int index)
	{
		for (auto v : vertices)
			v->layer = -1;

		std::queue<Vertex<T>*> marked;
		int layer = 0;

		Vertex<T>* currentVertex = vertices[index];
		currentVertex->layer = layer;
		marked.push(currentVertex);

		layer++;
		for (auto neighbor : currentVertex->neighbors)
		{	
			neighbor->layer = layer;
			marked.push(neighbor);
		}
		

		while (!marked.empty())
		{
			Vertex<T>* vertex = marked.front();
			marked.pop();


			for (auto neigbor : vertex->neighbors)
			{
				if (neigbor->layer == -1)
				{
					neigbor->layer = layer;
					marked.push(neigbor);
				}
			}


			if (marked.empty() || vertex->layer != marked.front()->layer)
				layer++;
		}
	};

	std::vector<std::wstring> ToStringArray()
	{
		std::vector<std::wstring> lines;

		for (Vertex<T>* vertex : vertices)
		{
			lines.push_back(vertex->ToString());
		}

		return lines;
	};

	std::vector<std::wstring> ToStringWithLayerArray()
	{
		std::vector<std::wstring> lines;

		for (Vertex<T>* vertex : vertices)
		{
			lines.push_back(vertex->ToStringWithLayer());
		}

		return lines;
	};
};

