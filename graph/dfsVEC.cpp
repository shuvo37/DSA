		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

    bool vis[mx];
    vector<int>adj[mx];





void dfs(int node)
{

   vis[node]=1;

     cout<<node<<" ";

     

      for(auto it =adj[node].begin();it!=adj[node].end();it++)
      {

          if(!vis[*it])
          {

             dfs(*it);

          }


      }



}





int main(){
  

   int n,m;

    cin>>n>>m;


    for(int i=0;i<=n;i++)vis[i]=false;



    	int x,y;

      for(int i=0;i<m;i++)
      {

       cin>>x>>y;

       adj[x].push_back(y);
       adj[y].push_back(x);
      }

    dfs(1);


}