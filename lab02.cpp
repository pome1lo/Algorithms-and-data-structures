#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void BFS(bool(&matrix)[10][10], int verh = 1);
void BFS(vector <int>* spisSmej, int verh = 1);
void BFSr(vector <int>* spisReber, int verh = 1);
void DFS(bool(&matrix)[10][10], int verh = 1);
void DFS(vector <int>* spisSmej, int verh = 1);
void DFSr(vector <int>* spisReber, int verh = 1);

void main()
{
    bool matrixSmej[10][10] = {
        // 1  2  3  4  5  6  7  8  9  10
          {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},// 1
          {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},// 2
          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},// 3
          {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},// 4
          {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},// 5
          {0, 0, 0, 1, 1, 0, 0, 0, 1, 0},// 6
          {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},// 7
          {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},// 8
          {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},// 9
          {0, 0, 0, 0, 0, 0, 0, 0, 1, 0} // 10
    };

    vector <int> spisReber[22] = { {1,2}, {1,5}, {2,1}, {2,7}, {2,8}, {3,8}, {4,6}, {4,9}, {5,1}, {5,6},
                                   {6,4}, {6,5}, {6,9}, {7,2}, {7,8}, {8,2}, {8,3}, {8,7}, {9,4}, {9,6},
                                   {9,10}, {10,9} };

    vector <int> spisSmej[10] = { {2,5}, {1,7,8}, {8}, {6,9}, {1,6}, {4,5,9}, {2,8}, {2,3,7}, {4,6,10}, {9} };

    BFS(matrixSmej, 1);
    BFS(spisSmej, 3);
    BFSr(spisReber, 5);

    DFS(matrixSmej, 3);
    DFS(spisSmej, 5);
    DFSr(spisReber, 7);
}

void BFS(bool(&matrix)[10][10], int verh = 1) //в ширину
{
    if (verh - 1 < 0 || verh - 1 > 9) {
        cout << "\n\nWrong vertex selected!!!\n\n";
        return;
    }

    cout << "\n\nBreadth Traversal - Adjacency Matrix\n";

    queue <int> Queue;
    int nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i] = 0;
    }

    Queue.push(verh - 1);

    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (int j = 0; j < 10; j++) {
            if (matrix[node][j] == true && nodes[j] == 0) {
                Queue.push(j);
                nodes[j] = 1;
            }
        }
        cout << "\nTop ->  " << node + 1;
    }
}

void BFS(vector <int>* spisSmej, int verh = 1)
{
    if (verh - 1 < 0 || verh - 1 > 9)
    {
        cout << "\n\nWrong vertex selected!!!\n\n";
        return;
    }

    cout << "\n\nBreadth Traversal - Adjacency List\n";

    queue <int> Queue;
    int nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i] = 0;
    }

    Queue.push(verh - 1);

    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;

        for (int n = 0; n < spisSmej[node].size(); n++) {
            if (nodes[spisSmej[node].at(n) - 1] == 0) {

                Queue.push(spisSmej[node].at(n) - 1);

                nodes[spisSmej[node].at(n) - 1] = 1;
            }
        }
        cout << "\nTop ->  " << node + 1;
    }
}

void BFSr(vector <int>* spisReber, int verh = 1)
{
    if (verh - 1 < 0 || verh - 1 > 9) {
        cout << "\n\nWrong vertex selected!!!\n\n";
        return;
    }

    cout << "\n\nBreadth Traversal - List of Edges\n";

    queue <int> Queue;
    int nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i] = 0;
    }

    Queue.push(verh - 1);

    while (!Queue.empty()) {
        int j = 0;
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;

        for (int i = 0; i < 22; i++) {
            if (spisReber[i].at(0) == node + 1) {
                if (nodes[spisReber[i].at(1) - 1] == 0)
                {
                    Queue.push(spisReber[i].at(1) - 1);

                    nodes[spisReber[i].at(1) - 1] = 1;
                }
            }
        }

        cout << "\nВершина ->  " << node + 1;
    }
}

void DFS(bool(&matrix)[10][10], int verh = 1) //в глубину
{
    if (verh - 1 < 0 || verh - 1 > 9) {
        cout << "\n\nWrong vertex selected!!!\n\n";
        return;
    }

    cout << "\n\nDepth Traversal - Adjacency Matrix\n";
    stack<int> Stack;
    int nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i] = 0;
    }

    Stack.push(verh - 1);

    while (!Stack.empty()) {
        int node = Stack.top();
        Stack.pop();

        if (nodes[node] == 2) continue;

        nodes[node] = 2;

        for (int j = 9; j >= 0; j--) {
            if (matrix[node][j] == 1 && nodes[j] != 2) {
                Stack.push(j);
                nodes[j] = 1;
            }
        }

        cout << "\nTop ->  " << node + 1;
    }
}

void DFS(vector <int>* spisSmej, int verh = 1)
{
    if (verh - 1 < 0 || verh - 1 > 9) {
        cout << "\n\nWrong vertex selected!!!\n\n";
        return;
    }

    cout << "\n\nDepth-first Traversal - Adjacency List\n";

    stack<int> Stack;
    int nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i] = 0;
    }

    Stack.push(verh - 1);

    while (!Stack.empty()) {
        int node = Stack.top();
        Stack.pop();

        if (nodes[node] == 2) continue;

        nodes[node] = 2;

        for (int n = spisSmej[node].size() - 1; n >= 0; n--) {
            if (nodes[spisSmej[node].at(n) - 1] == 0) {

                Stack.push(spisSmej[node].at(n) - 1);

                nodes[spisSmej[node].at(n) - 1] = 1;
            }
        }

        cout << "\nВершина ->  " << node + 1;
    }
}

void DFSr(vector <int>* spisReber, int verh = 1)
{
    if (verh - 1 < 0 || verh - 1 > 9) {
        cout << "\n\nWrong vertex selected!!!\n\n";
        return;
    }

    cout << "\n\nDepth-first Traversal - List of Edges\n";

    stack<int> Stack;
    int nodes[10];

    for (int i = 0; i < 10; i++) {
        nodes[i] = 0;
    }

    Stack.push(verh - 1);

    while (!Stack.empty()) {
        int node = Stack.top();
        Stack.pop();

        if (nodes[node] == 2) continue;

        nodes[node] = 2;

        for (int i = 21; i >= 0; i--) {
            if (spisReber[i].at(0) == node + 1) {
                if (nodes[spisReber[i].at(1) - 1] == 0)
                {
                    Stack.push(spisReber[i].at(1) - 1);

                    nodes[spisReber[i].at(1) - 1] = 1;
                }
            }
        }

        cout << "\nВершина ->  " << node + 1;
    }
}