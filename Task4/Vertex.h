#pragma once
#include <vector>

class Vertex
{
public:
    int layer;
    const char* value;
    std::vector<Vertex*> neighbors;

    Vertex();
    Vertex(const char* value);
    Vertex(std::vector<Vertex*> neighbors);
    ~Vertex();
};

