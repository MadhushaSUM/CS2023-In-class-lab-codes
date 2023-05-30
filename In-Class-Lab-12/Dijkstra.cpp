#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> dijkstra(const vector<vector<int>>& adj_matrix,const int source) {
    vector<int> distances(adj_matrix.size(), INT_MAX);

    distances[source] = 0;

    set<int> processed;

    // Iterate over all the vertices.
    for (int i = 0; i < adj_matrix.size(); i++) {
        // Find the vertex with the minimum distance.
        int min_vertex = -1;
        for (int j = 0; j < adj_matrix.size(); j++) {
            if (!processed.count(j) && (min_vertex == -1 || distances[j] < distances[min_vertex])) {
                min_vertex = j;
            }
        }

        // If the vertex has not been processed yet, update the distances of its neighbors.
        if (min_vertex != -1) {
            processed.insert(min_vertex);
            for (int j = 0; j < adj_matrix.size(); j++) {
                if (adj_matrix[min_vertex][j] != 0) {
                    distances[j] = min(distances[j], distances[min_vertex] + adj_matrix[min_vertex][j]);
                }
            }
        }
    }
    return distances;
}

int main() {
    // adjacency matrix.
    vector<vector<int>> adj_matrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    // starting city
    const int STARTING_CITY = 0;

    vector<int> distances = dijkstra(adj_matrix, STARTING_CITY);

    // Print the distances
    for (int i = 0; i < distances.size(); i++) {
        cout << "The distance from vertex "<< STARTING_CITY <<" to vertex " << i << " is " << distances[i] << endl;
    }

    return 0;
}
