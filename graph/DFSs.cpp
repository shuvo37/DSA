		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define white 1
#define black 2
#define dblack 3
   const int mx=1e5;
   int adj[200][200];
     vector<int>g[4];
   int color[200];
     
    int node,edges;
  


 void dfsVisit(int x){


    color[x]=black;
  
    
       for(int i=0;i<node;i++){

             if(g[x][i]==1){

              if(color[i]==white){

                   cout<<i<<endl;
                     dfsVisit(i);
         
              }


             }


       }

       color[x]=dblack;
       

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

           g[x].push_back(1);
           g[y].push_back(1);

       }

     /* for(auto x:g)
      {

      for(auto y:x)
      {


     cout<<y<<" ";


      }

    cout<<"\n";
      }*/


       dfs();

/*

  0 1
  0 2
  0 3
  1 3
  2 3

  */


}