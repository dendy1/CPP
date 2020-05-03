#pragma once
#include <vector>
#include <string>

template <class T>
class Vertex
{
public:
    T value;
    int layer;
    std::vector<Vertex<T>*> neighbors;

    Vertex()
    {
        this->neighbors = std::vector<Vertex<T>*>();
        this->layer = -1;
    };

    Vertex(T value)
    {
        this->value = value;
        this->neighbors = std::vector<Vertex<T>*>();
        this->layer = -1;
    };

    Vertex(std::vector<Vertex<T>*> neighbors)
    {
        this->neighbors = neighbors;
        this->layer = -1;
    };

    ~Vertex()
    {
    };

    std::wstring ToString()
    {
        std::stringstream ss;

        ss << value << " | <";

        for (int i = 0; i < neighbors.size(); i++)
        {
            ss << neighbors[i]->value;

            if (i != neighbors.size() - 1)
            {
                ss << ", ";
            }
        }

        ss << ">";

        std::string s = ss.str();
        return std::wstring(s.begin(), s.end());
    };

    std::wstring ToStringWithLayer()
    {
        std::stringstream ss;

        ss << value << " | " << layer;

        std::string s = ss.str();
        return std::wstring(s.begin(), s.end());
    };
};

