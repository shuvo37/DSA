			//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define white 1
#define black 2
#define dblack 3
   const int mx=1e6;
   int adj[200][200];
   int color[200];
     int stime[200];
      int etime[200];
    int node,edges;
      int time=1;


 void dfsVisit(int x){


    color[x]=black;
     stime[x]=time;
       time++;

       for(int i=0;i<node;i++){

             if(adj[x][i]==1){

              if(color[x]==white){


                     dfsVisit(i);
         
              }


             }


       }

       color[x]=dblack;
        etime=time;time++;

 }



void dfs(){


  for(int i=0;i<node;i++ )
{

       color[i]=white;

}


  for(int i=0;i<node;i++){

  	    if(color[i]==white){

  	    	  dfsVisit(i);
  	    }
  }




}



int main(){
     cin>>node>>edges;

     int x,y;

       for(int i=0;i<edges;i++){
       
          cin>>x>>y;

          adj[x][y]=1;
          adj[y][x]=1;

       }


       dfs();




}