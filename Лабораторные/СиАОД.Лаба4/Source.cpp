#include <iostream>
#include<fstream>
#include<ctime>
#define infinuum 1000
using namespace std;
class graph
{
private:
	void fillThegraphMatrixFromFile(string filename, int **graphMatrix, int **AgraphMatrix, int **M, int **ostovTree, int vertexQuantity);
	void mathgraph(string filename, int &qua);
public:
	int qua;
	string filename;
	int **graphMatrix;
	int **AgraphMatrix;
	int **M;
	int **ostovTree;
	void floid(int **a, int qua, int **M);
	void OstovTree(int **graph, int **ostovTree, int vertexQua);
	void printGraph(int vertexQuantity, int **matr);
	graph(string Filename)
	{
		filename = Filename;
		mathgraph(filename, qua);
		graphMatrix = new int*[qua];
		AgraphMatrix = new int*[qua];
		M = new int*[qua];
		ostovTree = new int*[qua];
		for (int i = 0; i < qua; i++)
		{
			graphMatrix[i] = new int[qua];
			AgraphMatrix[i] = new int[qua];
			M[i] = new int[qua];
			ostovTree[i] = new int[qua];
		}
		fillThegraphMatrixFromFile(filename, graphMatrix, AgraphMatrix, M, ostovTree, qua);
	}

};
int main()
{
	string filename = "graphMatrix.txt";
	graph newGraph(filename);
	cout << "graph Matrix:" << endl;
	newGraph.printGraph(newGraph.qua, newGraph.graphMatrix);
	newGraph.floid(newGraph.AgraphMatrix, newGraph.qua, newGraph.M);
	//печать матрицы кратчайших путей
	cout << "Shortest paths matrix: " << endl;
	newGraph.printGraph(newGraph.qua, newGraph.AgraphMatrix);
	//Печать матрицы маршрутов
	cout << "Transit vertexes matrix: " << endl;
	newGraph.printGraph(newGraph.qua, newGraph.M);
	newGraph.OstovTree(newGraph.graphMatrix, newGraph.ostovTree, newGraph.qua);
	//Печать матрицы остовного дерева
	cout << "Ostov Tree Matrix: " << endl;
	newGraph.printGraph(newGraph.qua, newGraph.ostovTree);
	system("pause");
	return 0;
}

void graph::fillThegraphMatrixFromFile(string filename, int **graphMatrix, int **AgraphMatrix, int **M, int **ostovTree, int vertexQuantity)
{
	ifstream stream;
	stream.open(filename);
	stream >> vertexQuantity;
	//Заполнение матрицы смежности
	for (int i = 0; i < vertexQuantity; i++)
	{
		for (int j = 0; j < vertexQuantity; j++)
		{
			stream >> graphMatrix[i][j];
			AgraphMatrix[i][j] = graphMatrix[i][j];
			M[i][j] = 0;
			ostovTree[i][j] = 0;
			if (i == j)
			{
				graphMatrix[i][j] = 0;
				graphMatrix[j][i] = 0;
				AgraphMatrix[i][j] = 0;
				AgraphMatrix[j][i] = 0;
			}
		}
	}
	stream.close();
}
void graph::mathgraph(string filename, int &qua)
{
	char c;
	cout << "You can choose filling the graph matrix randomly(R) or make it on your own(Any other literal) or you can click F to read matrix from file " << endl;
	cin >> c;
	if (c == 'F' || c == 'f')
	{
		ifstream stream;
		stream.open(filename);
		stream >> qua;
		stream.close();
		return;
	}
	ofstream fout;
	fout.open(filename);
	int variable;
	cout << "enter vertexes quantity ";
	cin >> qua;
	fout << qua << endl;
	cout << endl;
	if (c == 'R' || c == 'r')
	{
		srand(time(NULL));
		for (int i = 0; i < qua; i++)
		{
			
			for (int j = 0; j < qua; j++)
				fout << rand() % 20 + 1 << " ";
			fout << endl;
		}
	}
	else
	{
		for (int i = 0; i < qua; i++)
		{
			for (int j = 0; j < qua; j++)
			{
				cin >> variable;
				fout << variable << " ";
			}
			cout << " next string" << endl;
			fout << endl;
		}
	}
	fout.close();
}
void graph::floid(int **a, int qua, int **M)
{
	for (int i = 0; i < qua; i++)
		a[i][i] = 0;
	for (int i = 0; i < qua; i++)
		for (int j = 0; j < qua; j++)
			if (a[i][j] == 0)
				a[i][j] = infinuum;
	for (int k = 0; k < qua; k++)
		for (int i = 0; i < qua; i++)
			for (int j = 0; j < qua; j++)
				if (a[i][k] + a[k][j] < a[i][j])
				{
					a[i][j] = a[i][k] + a[k][j];
					/*a[j][i] = a[i][k] + a[k][j];*/
					M[i][j] = k + 1;
					/*M[j][i] = k + 1;*/
				}
	for (int i = 0; i < qua; i++)
		for (int j = 0; j < qua; j++)
			if (a[i][j] == infinuum)
			{
				a[i][j] = 0;
				M[i][j] = 0;
			}
	//for (int i = 0; i < qua; i++)
	//{
	//	a[i][i] = 0;
	//	M[i][i] = 0;
	//}
}
void graph::printGraph(int vertexQuantity, int **matr)
{
	for (int i = 0; i < vertexQuantity; i++)
	{
		for (int j = 0; j < vertexQuantity; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}
}
void graph::OstovTree(int **graph, int **ostovTree, int vertexQua)
{
	int *tree_id = new int[vertexQua];
	int edgeQua = 0;
	bool marki = false, markj = false;
	struct edge {
		int vertex1 = NULL;
		int vertex2 = NULL;
		int weight = NULL;
	};

	for (int i = 0; i < vertexQua; i++)
		tree_id[i] = infinuum;
	//сделать граф неориентированным
	for (int i = 0; i < vertexQua; i++)
	{
		for (int j = 0; j < vertexQua; j++)
		{
			if (graph[i][j] == 0)
				graph[i][j] = 0;
			if (graph[i][j] != 0 && graph[j][i] != 0)
			{
				if (graph[i][j] > graph[j][i] && graph[j][i] != 0)
					graph[i][j] = graph[j][i];
				else if (graph[i][j] < graph[j][i] && graph[i][j] != 0)
					graph[j][i] = graph[i][j];
			}
			else if (graph[i][j] != 0 && graph[j][i] == 0)
				graph[j][i] = graph[i][j];
			else if (graph[j][i] != 0 && graph[i][j] == 0)
				graph[i][j] = graph[j][i];
		}
	}

	//считаем число ребер в графе
	for (int i = 0; i < vertexQua; i++)
		for (int j = 0; j < vertexQua; j++)
		{
			if (graph[i][j] != 0)
				edgeQua++;
		}
	edge *graphEdges = new edge[edgeQua];
	int z = 0;
	//заполняем ребро необходимыми данными
	for (int i = 0; i < vertexQua; i++)
		for (int j = 0; j < vertexQua; j++)
		{
			if (graph[i][j] != 0)
			{
				graphEdges[z].vertex1 = i;
				graphEdges[z].vertex2 = j;
				graphEdges[z].weight = graph[i][j];
				z++;
			}
		}
	//Сортируем рёбра
	for (int i = 0; i < edgeQua; i++)
		for (int j = i + 1; j < edgeQua - 1; j++)
		{
			if (graphEdges[i].weight > graphEdges[j].weight)
			{
				edge temp = graphEdges[i];
				graphEdges[i] = graphEdges[j];
				graphEdges[j] = temp;
			}
		}
	//Заполняем матрицу остовного дерева. это массив для компонент связности
	int *connectionComponent = new int[vertexQua];
	int connectCount = 0;
	for (int i = 0; i < vertexQua; i++)
		connectionComponent[i] = infinuum;
	//Заполняем матрицу остовного дерева
	for (int i = 0; i < edgeQua; i++)
	{
		for (int j = 0; j < vertexQua; j++)
		{
			if (graphEdges[i].vertex1 == tree_id[j])
				marki = true;
			if (graphEdges[i].vertex2 == tree_id[j])
				markj = true;
		}
		if (marki&markj)
		{
			if (connectionComponent[graphEdges[i].vertex1] != infinuum && connectionComponent[graphEdges[i].vertex2] != infinuum)
			{
				if (connectionComponent[graphEdges[i].vertex1] != connectionComponent[graphEdges[i].vertex2])
				{
					ostovTree[graphEdges[i].vertex1][graphEdges[i].vertex2] = graph[graphEdges[i].vertex1][graphEdges[i].vertex2];
					ostovTree[graphEdges[i].vertex2][graphEdges[i].vertex1] = graph[graphEdges[i].vertex1][graphEdges[i].vertex2];
					int f = connectionComponent[graphEdges[i].vertex2];
					for (int k = 0; k < vertexQua; k++)
						if (connectionComponent[k] == connectionComponent[graphEdges[i].vertex2])
							connectionComponent[k] = connectionComponent[graphEdges[i].vertex1];
				}
			}
			marki, markj = false;
			continue;
		}

		ostovTree[graphEdges[i].vertex1][graphEdges[i].vertex2] = graphEdges[i].weight;
		ostovTree[graphEdges[i].vertex2][graphEdges[i].vertex1] = graphEdges[i].weight;

		if (connectionComponent[graphEdges[i].vertex1] != infinuum)
		{
			for (int k = 0; k < vertexQua; k++)
				if (connectionComponent[k] == connectionComponent[graphEdges[i].vertex2] && connectionComponent[k] != infinuum)
					connectionComponent[k] = connectionComponent[graphEdges[i].vertex1];


			/*connectionComponent[graphEdges[i].vertex2] = connectionComponent[graphEdges[i].vertex1];*/
		}
		else if (connectionComponent[graphEdges[i].vertex2] != infinuum)
		{
			for (int k = 0; k < vertexQua; k++)
				if (connectionComponent[k] == connectionComponent[graphEdges[i].vertex1] && connectionComponent[k] != infinuum)
					connectionComponent[k] = connectionComponent[graphEdges[i].vertex2];

			/*connectionComponent[graphEdges[i].vertex1] = connectionComponent[graphEdges[i].vertex2];*/
		}
		else
		{
			connectionComponent[graphEdges[i].vertex1] = connectCount;
			connectionComponent[graphEdges[i].vertex2] = connectCount;
			connectCount++;
		}
		int k = 0;
		while (tree_id[k] != infinuum && k < vertexQua)
		{
			k++;
		}
		//условие конца обхода вершин
		if (k == vertexQua)
			break;
		if (marki & !markj)
			tree_id[k] = graphEdges[i].vertex2;
		else if (!marki&markj)
			tree_id[k] = graphEdges[i].vertex1;
		else if (k < vertexQua - 1)
		{
			tree_id[k] = graphEdges[i].vertex1;
			tree_id[k + 1] = graphEdges[i].vertex2;
		}
		marki = false;
		markj = false;
	}
	delete graphEdges;
	delete tree_id;
}
