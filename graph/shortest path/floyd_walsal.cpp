
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5;
      int n,m;





      void floydWarshall(vector<vector<int>>dist)
      {

          for(int i=1;i<=n;i++)
          {
            dist[i][i]=0;

          }

         for(int k=1;k<=n;k++)
         {
             for(int i=1;i<=n;i++)
             {
                for(int j=1;j<=n;j++)
                {


                 if(dist[i][j]>dist[i][k]+dist[k][j]&&dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX)
                 {

                       dist[i][j]=dist[i][k]+dist[k][j];

                 }


                }


             }

         }


         for(int i=1;i<=n;i++ )
         {
            for(int j=1;j<=n;j++)
            {

              if(dist[i][j]==INT_MAX)
              {

                  cout<<-1<<endl;


              }
              else{

                 cout<<"distant "<<i<<" "<<j<<" "<<dist[i][j]<<endl;
              }



            }

         }





      }



int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);


   cin>>n>>m;


    vector<vector<int>>g(n+4,vector<int>(n+4,INT_MAX));

       int u,v,w;

       for(int i=0;i<m;i++)
       {

          cin>>u>>v>>w;

            g[u][v]=w;
       }


       floydWarshall(g);




}
