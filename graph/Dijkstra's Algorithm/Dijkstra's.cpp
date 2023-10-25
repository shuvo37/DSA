#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // Pair of (vertex, weight)

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<pii>>& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap priority queue

    distances[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
      int dist_u = pq.top().first;
        int u = pq.top().second;
        cout<<" when vertex "<<u<<" dist "<<dist_u<<endl;
        pq.pop();

        if (dist_u > distances[u]) {
          cout<<"  continue "<<dist_u<<"  distance"<<distances[u]<<endl;
            continue; // Skip outdated entries in the priority queue
        }

        for (const pii& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            cout<<" then vertex "<<v<<" cost "<<weight<<endl;

            if (dist_u + weight < distances[v]) {
                cout<<" enter  "<<v<<" cost "<<weight<<endl;
                distances[v] = dist_u + weight;
                pq.push(make_pair(distances[v], v));
                cout<<" update value vectx"<<v<<" cost "<< distances[v]<<endl;
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<pii>> graph(numVertices + 1); // 1-based indexing
    int u, v, weight;

    for (int i = 0; i < numEdges; ++i) {
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight); // For undirected graph
    }

    int source=0;


    vector<int> distances(numVertices + 1, INT_MAX);
    dijkstra(graph, source, distances);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 1; i <= numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "Not reachable";
        } else {
            cout << distances[i];
        }
        cout << "\n";
    }

    return 0;
}

/*


0 2 9
0 5 7
1 3 8
1 2 2
2 4 11
2 5 10
3 4 6
4 5 15





*/
