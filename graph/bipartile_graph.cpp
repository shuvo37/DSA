		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

     int vis[100],col[100];

       vector<int>v[100];
         int n,m;


 bool dfs(int x,bool c)
 {
 

      vis[x]=1;
      col[x]=c;


       for(auto ch:v[x])
       {

        if(vis[ch]==0)
        {

        if(dfs(ch,c^1)==false)return false;




        }
        else 

        {


         if(col[ch]==c)
         {
         	return false;
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

      bool ans=dfs(1,1);

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