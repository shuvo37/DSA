		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

      int n,m;
      vector<int>v[mx];

      stack<int>ans;
      bool vis[6009];


   void dfsv(int x)
   {

       vis[x]=1;


    for(auto c:v[x])
  {

      if(!vis[c])
      {


       dfsv(c);


      }

  }
          

   ans.push(x);


   }




  void dfs()

  {
  
  for(int i=1;i<=n;i++)
  {

      if(!vis[i])
      {


       dfsv(i);


      }

  }



  }



int main(){
   
      
      cin>>n>>m;
     int x,y;


    while(m--)
    {

   cin>>x>>y;


     v[x].push_back(y);
  

    }

   dfs();

     
      while(!ans.empty())
      {


      int curr=ans.top();

        cout<<curr<<" ";
             ans.pop();

      }

}