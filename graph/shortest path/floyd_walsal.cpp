#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=500;

    int n,m,w;

      void floydWarshall(vector<vector<int>>dist)
      {


              for(int i=0;i<n;i++){dist[i][i]=0;}
          for(int k=0;k<n;k++)
          {

            for(int i=0;i<n;i++ )
            {
               for(int j=0;j<n;j++)
               {


                 if(dist[i][j]>dist[i][k]+dist[k][j]&&dist[i][k]!=INT_MAX
                    &&dist[k][j]!=INT_MAX)
                 {

                    dist[i][j]= dist[i][k]+dist[k][j];


                 }



               }



            }


          }




       for(int i=0;i<n;i++ )
            {
               for(int j=0;j<n;j++)
               {


                 if(dist[i][j]==INT_MAX)
                 {

                   cout<<-1<<endl;

                 }
                 else{

                   cout<< dist[i][j]<<endl;

                 }


               }



            }







      }


int main(){



       vector<vector<int>>graph(mx,vector<int>(mx,INT_MAX));



   cin>>n>>m;

    for(int i=0;i<m;i++)
    {
       int u,v;
         cin>>u>>v>>w;


          graph[u][v]=w;

    }

      floydWarshall(graph);


}
