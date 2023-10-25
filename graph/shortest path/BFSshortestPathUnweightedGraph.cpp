#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPathBFS(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end)
      
            break;

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = curr;
            }
        }
    }

    // Retrieve the shortest path
    vector<int> path;
    if (parent[end] == -1) {
        cout << "No path exists from " << start << " to " << end << endl;
        return path;
    }

    int node = end;
    while (node != -1) {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 7;  // Number of nodes in the graph

    // Adjacency list representation of the graph
    vector<vector<int>> graph(n);

    // Add edges to the graph
    graph[0] = {1, 2};
    graph[1] = {3,4};
    graph[2] = {};
    graph[3] = {4,5};
    graph[4] = {2,6};
    graph[5] = {6};
    graph[6] = {2};

    int start = 0;
    int end = 6;

    vector<int> shortestPath = shortestPathBFS(graph, start, end);

    if (!shortestPath.empty()) {
        cout << "Shortest path from " << start << " to " << end << ": ";
        for (int node : shortestPath) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
