		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;
   int parent[mx];
   int n;


  int makeSet(int x)

  {


  parent[x]=x;


  }


    void init()
    {


  for(int i=1;i<=n;i++)
  {

  makeSet(i);


  }



    }

   int find(int x)
   {

   if(x==parent[x]){return x;}


        return find(parent[x]);
   }

   void Union(int u,int v)
   {


   int p=find(u);

   int q=find(v);

  //  cout<<parent[p]<<endl;
     //    cout<<parent[q]<<endl;

     if(p!=q)
     {

    parent[q]=p;
   // cout<<parent[q]<<endl;

     }


   }


int main(){

	  cin>>n;

	  init();
    
       Union(2,3);
      Union(1,2);
 


    cout<<find(2)<<" "<<find(3)<<endl;
    cout<<find(1)<<" "<<find(2)<<endl;


}