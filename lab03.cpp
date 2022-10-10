#include <limits.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

#define SIZE 9

void Dijkstra(int graph[SIZE][SIZE], int src);
void Print(int dist[], int n);
 int minDistance(int dist[], bool sptSet[]);

void main()
{
	char var;
	bool check = true;
	int graph[SIZE][SIZE] = {
		/*       A   B   C   D   E   F   G   H   I  */
		/*A*/  { 0,  7,  10, 0,  0,  0,  0,  0,  0  },
		/*B*/  { 7,  0,  0,  0,  0,  9,  27, 0,  0  },
		/*C*/  { 10, 0,  0,  0,  31, 8,  0,  0,  0  },
		/*D*/  { 0,  0,  0,  0,  32, 0,  0,  17, 21 },
		/*E*/  { 0,  0,  31, 32, 0,  0,  0,  0,  0  },
		/*F*/  { 0,  9,  8,  0,  0,  0,  0,  11, 0  },
		/*G*/  { 0,  27, 0,  0,  0,  0,  0,  0,  15 },
		/*H*/  { 0,  0,  0,  17, 0,  11, 0,  0,  15 },
		/*I*/  { 0,  0,  0,  21, 0,  0,  15, 15, 0  }
	};
	do {
		cout << "Enter the vertex to start from ";
		cin >> var;
		if ((int)var < 65 || (int)var > 73) 
		{
			cout << "You entered the wrong vertex to start." << endl;
		}
		else 
		{
			check = false;
		}
	} while (check);

	Dijkstra(graph, (int)var - 65);
}

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX;
	int min_index;

	for (int i = 0; i < SIZE; i++)
	{
		if (sptSet[i] == false && dist[i] <= min)
		{
			min = dist[i], min_index = i;
		}
	}
	return min_index;
}

void Print(int dist[], int n)
{
	cout << "Vertex distance from the source" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << char(i + 65) << "\t\t" << dist[i] << endl;
	}
}

void Dijkstra(int graph[SIZE][SIZE], int src)
{
	int dist[SIZE];
	bool sptSet[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		dist[i] = INT_MAX, sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < SIZE - 1; count++) {
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < SIZE; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	Print(dist, SIZE);
}
