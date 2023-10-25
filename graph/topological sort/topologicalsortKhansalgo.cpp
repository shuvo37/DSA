
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5+2;

   int n,m;
     bool  vis[mx];
     vector<int>adj[mx];
     int in[mx];

   void bfs()
   {
       queue<int>q;

       for(int i=1;i<=n;i++){

         if(in[i]==0)
         {
          q.push(i);

         }

       }

       vector<int>ans;

     while(!q.empty())
     {

       int curr=q.front();
            q.pop();

         ans.push_back(curr);

         for(auto v:adj[curr])
         {
             --in[v];

           if(in[v]==0)
           {

            q.push(v);

           }


         }




     }


    for(auto x:ans)
    {

      cout<<x<<" ";

    }
      cout<<"\n";



   }


int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);


      cin>>n>>m;

      for(int i=1;i<=m;i++)
      {
         int u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         in[v]++;

      }


      bfs();



}
