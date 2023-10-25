				//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

     int vis[100],col[100];

       vector<int>v[100];
         int n,m;


 bool bfs(int x,bool c)
 {
 

   queue<int>q;

     q.push(x);

     col[x]=c;
      vis[x]=1;

      while(!q.empty())
      {


       int cur=q.front();

       q.pop();

       for(auto x:v[cur])
       {

         
          if(vis[x]==0)
          {

            col[x]=col[cur]^1;
             vis[x]=1;
              q.push(x);

          }

          else
          {

             if(col[x]==col[cur])
             {
             return false;
             }


          }


       }



      }


 return true;


 }





int main(){
  
    cin>>n>>m;

   int x,y;
    for(int i=0;i<m;i++)
    {

    cin>>x>>y;

     v[x].push_back(y);

      v[y].push_back(x);

    }

      bool ans=bfs(1,1);

    if(ans)
    {

    cout<<"YES\n";

    }
    else
    {

     cout<<"NO\n";
    }
}
/*

 4 4
 3 2
 2 4
 4 1
 1 3

*/

/*

 4 3

 1 2
 2 3
 3 1


*/
/*
5 6
1 2
1 3
2 4
4 3
4 5
5 2


*/
