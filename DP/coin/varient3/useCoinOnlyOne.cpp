		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;
     int k,n;
   int dp[k+1][n+1];
   int coin[k+1];




    void dp()
    {


  dp[0][0]=1;

  for(int j=1;j<=k;j++)
  {
   for(int i=1;i<=n;i++)
   {

    if(dp[j-1][i]||(i>=coin[j]&&dp[j-1][i-coin[j]]))
    {

     dp[j][i]=1;

    }


   }
   


  }

  }





int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin>>n>>k;

     for(int i=1;i<=k;i++)
     {
      cin>>coin[i];
     }
  

     dp();

}