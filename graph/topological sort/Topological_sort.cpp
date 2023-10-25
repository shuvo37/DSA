#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5+1;

   bool vis[mx];
     vector<int>adj[mx];

      int n,m;
      stack<int>ans;

     void dfs(int u)
     {
        vis[u]=true;


       for(auto x:adj[u])
       {

          if(!vis[u])
          {
            dfs(u);

          }


       }

        ans.push(u);


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

     }

       for(int i=1;i<=n;i++)
       {

           if(!vis[i])
           {
               dfs(i);
           }

       }


         while(!ans.empty())
         {

           cout<<ans.top()<<" ";
           ans.pop();

         }

          cout<<"\n";

}
