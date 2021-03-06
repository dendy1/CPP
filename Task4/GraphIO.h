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

	// ��������� ������ �� ������
	std::vector<Vertex<int>*> vertices;
	for (int i = 0; i < strArr.GetCount(); i++)
	{
		nTokenPos = 0;
		strToken = strArr[i].Tokenize(_T("|"), nTokenPos);

		const size_t size = (strToken.GetLength() + 1);
		char* vertexString = new char[size];
		strcpy_s(vertexString, size, strToken);
		auto vertexValue = atoi(vertexString);

		strArr[i] = strArr[i].Tokenize(_T("|"), nTokenPos);

		if (!vertexValue)
		{
			const char* name = typeid(int).name();
			throw new BadVertexValueException(vertexString, name);
		}

		vertices.push_back(new Vertex<int>(vertexValue));
	}

	// ��� ������ ������� � ������ ��������� 
	for (int i = 0; i < strArr.GetCount(); i++)
	{
		auto currentVertex = vertices[i];
		strNeighbors = strArr[i];

		// Returns first token  
		char* token;
		char* rest = strNeighbors.GetBuffer();

		while (token = strtok_s(rest, ",", &rest))
		{
			auto vertexValue = atoi(token);

			if (!vertexValue)
			{
				const char* name = typeid(int).name();
				throw new BadVertexValueException(token, name);
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
				throw new VertexNotFoundException(token);
			}
		}

		strNeighbors.ReleaseBuffer();
	}

	// ��������� �� ������������ ��������� �����
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

inline void GraphIO::WriteGraphToFile(Graph<int>* graph, CString filename)
{
	CFile file(filename, CFile::modeReadWrite | CFile::modeCreate);

	for (auto vertex : graph->vertices)
	{
		file.Write(vertex->ToStringWithLayer().c_str(), vertex->ToStringWithLayer().size() * sizeof(TCHAR));
		file.Write(_T("\r\n"), 2 * sizeof(TCHAR));
	}

	file.Close();
}
