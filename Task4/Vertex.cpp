#include "pch.h"
#include "Vertex.h"

Vertex::Vertex()
{
	this->neighbors = std::vector<Vertex*>();
	this->layer = -1;
}

Vertex::Vertex(const char* value)
{
	this->value = value;
	this->layer = -1;
}

Vertex::Vertex(std::vector<Vertex*> neighbors)
{
	this->neighbors = neighbors;
	this->layer = -1;
}

Vertex::~Vertex()
{

}


