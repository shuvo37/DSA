#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

    bool vis[100];

      vector<int>adj[100];
        int timer;
        int in[100];
        int out[100];
        void dfs(int node,int par)
        {

               vis[node]=1;
                timer++;
                 in[node]=timer;
                 out[node]=timer;



               for(int x:adj[node])
               {

                 if(par==x) {continue;}

                 if(vis[x]==1)
                 {

                 out[node]=min(out[node],in[x]);

                 }
                 else{


                    dfs(x,node);

                    if(in[node]>out[x])
                    {

                   cout<<"There exit a bridege\n";

                    }

                 }


               }



        }


int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int n,m;


     cin>>n>>m;

      for(int i=0;i<m;i++)
      {
         int u,v;
          cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
      }


      dfs(0,-1);

}
