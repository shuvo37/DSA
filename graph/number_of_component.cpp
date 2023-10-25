		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

      vector<bool>vis;
    int n,m;
    vector<vector<int>>adj;

   vector<int>component;



int  get_com(int node)
{
     if(vis[node])
     {

        return 0;
     }

   vis[node]=1;

    

      int  ans=1;

      for(auto i:adj[node])
     {
      

          if(!vis[i])
          {

            ans+=get_com(i);
            vis[i]=1;

          }
     }


      


return ans;

}





int main(){
  


    cin>>n>>m;

      adj=vector<vector<int>>(n);

        vis=vector<bool>(n,0);

  //  for(int i=0;i<=n;i++)vis[i]=false;



   

      for(int i=0;i<m;i++)
      {

            int x,y;

       cin>>x>>y;

       adj[x].push_back(y);
       adj[y].push_back(x);
      }

     for(int i=0;i<n;i++)
     {

         if(!vis[i])
         {


         component.push_back(get_com(i));

         }


     }

     for(auto x:component){

        cout<<x<<"\n ";
     }

    


}