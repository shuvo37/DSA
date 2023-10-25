
    //header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e3;

    bool vis[mx];

vector<int>adj[mx];


   void BFS(int node)
   {


         queue<int>q;


         q.push(node);
         vis[node]=1;

         while(!q.empty())
         {


        int node=q.front();


          q.pop();

           cout<<node<<" ";

           for(auto x:adj[node])
           {


                if(!vis[x])
                {

                   vis[x]=1;

                   q.push(x);

                }



           }




         }







   }
int main(){



    int n;

    cin>>n;


    for(int i=0;i<=n;i++)vis[i]=false;



      int x,y;

      for(int i=1;i<=n;i++)
      {

       cin>>x>>y;

       adj[x].push_back(y);
       adj[y].push_back(x);
      }


     BFS(1);






}
