#pragma once
#include <iostream>
#include <exception>
#include <sstream>

struct BadVertexValueException : CException
{
private:
    const char* _value;
    const char* _type;

public:
    BadVertexValueException(const char* value, const char* type)
    {
        _value = value;
        _type = type;
    }

    const char* what() const throw ()
    {
        std::stringstream ss;
        ss << "Не удалось преобразовать значение <" << _value << "> к типу <" << _type << ">!";
        return ss.str().c_str();
    }
};

struct VertexNotFoundException : CException
{
private:
    const char* _vertex;

public:
    VertexNotFoundException(const char* value)
    {
        _vertex = value;
    }

    const char* what() const throw ()
    {
        std::stringstream ss;
        ss << "В исходном файле не найдена вершина <" << _vertex << ">!";
        return ss.str().c_str();
    }
};


struct NeighbourNotFoundException : CException
{
private:
    std::wstring _vertex;
    std::wstring _neighbour;

public:
    NeighbourNotFoundException(std::wstring vertex, std::wstring neighbour)
    {
        _vertex = vertex;
        _neighbour = neighbour;
    }

    const char* what() const throw ()
    {
        std::stringstream ss;
        ss << "В исходном файле у вершины <" << _neighbour.c_str() << "> не указана вершина <" << _vertex.c_str() << "> как соседская!";
        return ss.str().c_str();
    }
};