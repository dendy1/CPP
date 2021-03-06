#pragma once
#include "Vertex.h"
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

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

	void qqq(int index)
	{
		for (auto v : vertices)
			v->layer = -1;

		MarkNeighbors(index);

		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->layer > -1 || i == index)
				continue;

			MarkNeighbors(i);
		}

		sort(vertices.begin(), vertices.end(), [](const Vertex<T>* lhs, const Vertex<T>* rhs)
			{
				return lhs->layer < rhs->layer;
			});
	}

	void MarkNeighbors(int index)
	{
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

