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
   int parent[200];
    int dis[200];
     
    int node,edges;
  
void dfs(int st){


  for(int i=0;i<node;i++ )
{

       color[i]=white;
       parent[i]=INT_MIN;
         dis[i]=-1;

}


    dis[st]=0;
    parent[st]=-1;

    queue<int>q;

    q.push(st);

    while(!q.empty()){


     int x=q.front();

       q.pop();
       color[x]=black;
    
       for(int i=0;i<node;i++)
       {

             if(adj[x][i]==1)
             {

             	if(color[i]==white)
             	{


                   q.push(i);

                   // color[i]=black;
                    dis[i]=dis[x]+1;
                      parent[i]=x;

             	}





             }


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


       dfs(0);


  cout<<parent[2]<<endl;


}