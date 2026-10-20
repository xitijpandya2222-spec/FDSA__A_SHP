
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Depth First Search (DFS)
void DFS(int building, vector<int> graph[], bool visited[])
{
    visited[building] = true;
    cout << building << " ";

    for (int next : graph[building])
    {
        if (!visited[next])
        {
            DFS(next, graph, visited);
        }
    }
}

// Breadth First Search (BFS)
void BFS(int start, vector<int> graph[], int n)
{
    bool visited[100] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int building = q.front();
        q.pop();

        cout << building << " ";

        for (int next : graph[building])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n, edges;

    cout << "Enter number of buildings: ";
    cin >> n;

    vector<int> graph[100];

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter roads (building1 building2):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting building (0 to " << n - 1 << "): ";
    cin >> start;

    bool visited[100] = {false};

    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, graph, n);

    cout << endl;

    return 0;
}
