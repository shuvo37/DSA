		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5+10;
   int n,m;
   #define w 1
   #define gr 2
   #define bk 3
   vector<int>g[mx];

      int color[200];


      void dfsv(int x)
      {


    color[x]=gr;

    for(int i=0;i<n;i++)

    {

    if(g[x][i]==1&& color[x]==w)

    {
    dfsv(i);
    }
    }



    color[x]=bk;

      }


  void dfs()
  {

  for(int i=0;i<n;i++)
  {

  color[i]=w;

  }

  for(int i=0;i<n;i++)
  {

   if(color[i]==w)
   {

    dfsv(i);


   }


  }




  }


int main(){
 
  

       cin>>n>>m;

       for(int i=0;i<9;++i)
       {

        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);

        g[v2].push_back(v1);


       }


       dfs();


}