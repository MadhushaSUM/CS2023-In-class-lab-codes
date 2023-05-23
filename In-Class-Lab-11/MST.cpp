#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

// Function to add an edge to the graph
void addEdge(Graph& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(const Graph& graph, int startVertex) {
    int numVertices = graph.size();

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    vector<int> key(numVertices, INT_MAX);
    vector<bool> inMST(numVertices, false);
    vector<int> parent(numVertices, -1);

    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " --- " << i << "         weight  : " << key[i] << endl;
    }
}

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    // Adding edges to the graph
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 4, 5, 4);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 1, 4, 10);

    int startVertex = 0;
    primMST(graph, startVertex);

    return 0;
}
