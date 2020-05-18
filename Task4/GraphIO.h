#pragma once
#include "Graph.h"
#include "GraphException.h"
#include <typeinfo>
#include <atlstr.h>

class GraphIO
{
public:
	static Graph<int>* ReadGraphFromFile(CString filename);
	static void WriteGraphToFile(Graph<int>* graph, CString filename);
};

inline Graph<int>* GraphIO::ReadGraphFromFile(CString filename)
{
	CStringArray strArr;
	CString strLine;
	TRY
	{
		// Reading all file lines in CStringArray
		CStdioFile file(filename, CFile::modeRead);
		while (file.ReadString(strLine))
		{
			strArr.Add(strLine);
		}
	}
	CATCH_ALL(e)
	{
		e->ReportError(); // shows what's going wrong 
	}
	END_CATCH_ALL

	int nTokenPos;
	CStringA strToken, strNeighbors;

	// Заполняем массив из вершин
	std::vector<Vertex<int>*> vertices;
	for (int i = 0; i < strArr.GetCount(); i++)
	{
		nTokenPos = 0;
		strToken = strArr[i].Tokenize(_T("|"), nTokenPos);

		const size_t size = (strToken.GetLength() + 1);
		char* vertexString = new char[size];
		strcpy_s(vertexString, size, strToken);
		auto vertexValue = atoi(vertexString);

		if (!vertexValue)
		{
			const char* name = typeid(int).name();
			throw new BadVertexValueException(vertexString, name);
		}

		vertices.push_back(new Vertex<int>(vertexValue));
	}

	// Для каждой вершины в списке добавляем 
	for (int i = 0; i < strArr.GetCount(); i++)
	{
		auto currentVertex = vertices[i];

		nTokenPos = 1;
		// Парсим строку после `|`
		strNeighbors = strArr[i].Tokenize(_T("|"), nTokenPos);

		nTokenPos = 0;
		strToken = strNeighbors.Tokenize(",", nTokenPos);
		while (!strToken.IsEmpty())
		{
			const size_t size = (strToken.GetLength() + 1);
			char* vertexString = new char[size];
			strcpy_s(vertexString, size, strToken);
			auto vertexValue = atoi(vertexString);

			if (!vertexValue)
			{
				const char* name = typeid(int).name();
				throw new BadVertexValueException(vertexString, name);
			}

			auto neighbour = std::find_if(vertices.begin(), vertices.end(), [vertexValue](Vertex<int>* vertex) -> bool { return vertex->Compare(vertexValue); });

			if (neighbour != vertices.end())
			{
				if (currentVertex != *neighbour)
				{
					currentVertex->neighbors.push_back(*neighbour);
				}
			}
			else
			{
				throw new VertexNotFoundException(vertexString);
			}

			strToken = strNeighbors.Tokenize(",", nTokenPos);
		}
	}

	// Проверяем на правильность введённого файла
	for (int i = 0; i < strArr.GetCount(); i++)
	{
		Vertex<int>* currentVertex = vertices[i];

		for (Vertex<int>* neighbour : currentVertex->neighbors)
		{
			if (!(std::find(neighbour->neighbors.begin(), neighbour->neighbors.end(), currentVertex) != neighbour->neighbors.end()))
			{
				throw new NeighbourNotFoundException(currentVertex->ToString(), neighbour->ToString());
			}
		}
	}

	return new Graph<int>(vertices);
}
