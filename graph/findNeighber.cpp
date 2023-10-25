			//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;
   int adj[200][200];

int main(){

  //freopen("input",'r',stdin);
    int node,edges;

       cin>>node>>edges;

    int x,y;
       for(int i=0;i<edges;i++){

           cin>>x>>y;
              
            adj[x][y]=1;
            adj[y][x]=1;

       }

    /*   for(int i=0;i<node;i++){

          for(int j=0;j<node;j++){

           cout<<adj[i][j]<<" ";

          }

     cout<<"\n";

       }*/

      for(int i=0;i<node;i++){


            if(adj[0][i]==1){

            	  cout<<i<<" ";
            }

      }



}

/*

5 3

0 1
0 2
2 4



*/