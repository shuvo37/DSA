#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
   const int mx=1e5;
   int n,m;
 vector<pii>adj[mx];




     void dijkstra(vector<int>dis,int source)
     {

        dis[source]=0;
         priority_queue<pii,vector<pii>,greater<pii>>pq;


              pq.push({0,0});


              while(!pq.empty())
              {

               int  dist_u=pq.top().first;
               int   u=pq.top().second;


                  pq.pop();

                     if(dis[u]<dist_u)
                     {

                       continue;

                     }


                   for(auto node:adj[u])
                   {
                      int v=node.first;
                      int wt=node.second;



                       if(dist_u+wt<dis[v])
                       {

                          dis[v]= dist_u+wt;
                           pq.push({dis[v],v});
                       }


                   }




              }


         for(int i=0;i<=n;i++)
         {
               if(dis[i]==INT_MAX){cout<<"not reachable\n";continue;}
            cout<<dis[i]<<" \n";

         }

           cout<<"\n";

     }




int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    cin>>n>>m;


     int u,v;
     int w;

      for(int i=0;i<m;i++)
      {
         cin>>u>>v>>w;

           adj[u].push_back({v,w});

           adj[v].push_back({u,w});


      }


    vector<int>dist(mx,INT_MAX);

        dijkstra(dist,0);



}
