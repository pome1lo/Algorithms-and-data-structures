#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 
#define I INT_MAX

using namespace std;


struct Edge
{
    int start;
    int end;
    int weight;
};


void Prims(int graphMatrix[8][8])
{
    int x = 0;
    int y = 0;
    int visited[8];
    int currentEdge = 0;

    for (int i = 0; i < 8; i++)
    {
        visited[i] = false;
    }

    visited[0] = true;

    while (currentEdge < 7)
    {
        x = 0;
        y = 0;
        int min = I;

        for (int i = 0; i < 8; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < 8; j++)
                {
                    if (!visited[j])
                    {
                        if (min > graphMatrix[i][j])
                        {
                            min = graphMatrix[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }

        cout << "Вершина " << x + 1 << " - " << "Вершина " << y + 1 << "; Вес: " << graphMatrix[x][y] << endl;
        visited[y] = true;
        currentEdge++;
    }
}

void Kruslals(vector <Edge> edgeList)
{
    int n = 8;

    int connectedVert[8];

    for (int i = 0; i < n; i++)
    {
        connectedVert[i] = i;
    }

    sort(edgeList.begin(), edgeList.end(), [](Edge& a, Edge& b) { return a.weight < b.weight; });

    for (Edge& e : edgeList)
    {
        if (connectedVert[e.start] != connectedVert[e.end])
        {
            cout << "Вершина " << e.start << " - " << "Вершина " << e.end << "; Вес : " << e.weight << endl;

            int oldVert = connectedVert[e.start], newVert = connectedVert[e.end];

            for (int i = 0; i < n; i++)
            {
                if (connectedVert[i] == oldVert)
                {
                    connectedVert[i] = newVert;
                }
            }
        }
    }
}

void main()
{
    setlocale(LC_ALL, "Rus");
    
    int graphMatrix[8][8] = {
        /*    1  2   3   4   5   6   7  8  */
        /*1*/{I, 2 , I , 8 , 2 , I , I, I},
        /*2*/{2, I , 3 , 10, 5 , I , I, I},
        /*3*/{I, 3 , I , I , 12, I , I, 7},
        /*4*/{8, 10, I , I , 14, 3 , 1, I},
        /*5*/{2, 5 , 12, 14, I , 11, 4, 8},
        /*6*/{I, I , I , 3 , 11, I , 6, I},
        /*7*/{I, I , I , 1 , 4 , 6 , I, 9},
        /*8*/{I, I , 7 , I , 8 , I , 9, I}
    };
    vector <Edge> edgeList =
    {
        {1, 2, 2}, {1, 4, 8 }, {7, 5, 4 }, {1, 5, 2 },
        {2, 3, 3}, {2, 5, 5 }, {2, 4, 10}, {3, 5, 12},
        {3, 8, 7}, {4, 5, 14}, {4, 6, 3 }, {4, 7, 1 },
        {5, 8, 8}, {6, 7, 6 }, {7, 8, 9 }, {5, 6, 11}
    };
    cout << "Алгоритм Прима: Список ребер остовного дерева и их вес:\n";
    
    Prims(graphMatrix);
    
    cout << "\nAлгоритм Краскала: Список ребер остовного дерева и их вес:\n";
    
    Kruslals(edgeList);
}