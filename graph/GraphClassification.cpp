#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int EXPLORED = 1;
const int VISITED = 2;

vector<int> dfs_num;
vector<int> dfs_parent;
vector<vector<int>> AdjList;

void graphCheck(int u) {
   

     dfs_num[u]=EXPLORED;

     for(int i=0;i<AdjList[u].size();i++)
     {


        int v=AdjList[u][i];

        if(dfs_num[v]==UNVISITED)
        {


          dfs_parent[v]=u;

          graphCheck(v);


        }

        else if(dfs_num[v]==EXPLORED)
        {


        if(v==dfs_parent[u])
        {

     cout<<" two WAys "<<v<<" "<<u<<endl;
       }

       else
       {


        cout<<"Back Edge (Cycle): " << u << " - " << v << endl;

       }


        }

        else if(dfs_num[v]==VISITED)
        {


        cout << "Forward/Cross Edge: " << u << " - " << v << endl;

        }





     }









}

int main() {
    int v; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> v;

    AdjList.resize(v);
    dfs_num.assign(v, UNVISITED);
    dfs_parent.assign(v, -1);

    cout << "Enter the adjacency list:\n";
    for (int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": ";
        int numEdges;
        cin >> numEdges;
        cout << "Enter the connected vertices: ";
        for (int j = 0; j < numEdges; j++) {
            int vertex;
            cin >> vertex;
            AdjList[i].push_back(vertex);
        }
    }

    for (int i = 0; i < v; i++) {
        if (dfs_num[i] == UNVISITED) {
            graphCheck(i);
        }
    }

    return 0;
}