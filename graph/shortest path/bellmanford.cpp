
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;



// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(vector<Edge> &edges, int V, int E, int src) {
    // Create an array to store the shortest distances
    vector<int> distance(V, INT_MAX);

    // Initialize the distance of the source vertex to 0
    distance[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Negative-weight cycle found!" << endl;
            return;
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter source, destination, and weight for each edge:" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(edges, V, E, src);

    return 0;
}

