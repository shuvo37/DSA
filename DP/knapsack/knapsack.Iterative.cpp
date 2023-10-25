
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

   struct item{



    int weight;
    int value;


   };


   int Knapsack(int w,vector<item>it)
   {


    int n=it.size();

   vector<vector<int>>dp(n+1,vector<int>(w+1,0));

   for(int i=1;i<=n;i++)
   {

    for(int j=1;j<=w;j++)
    {


    if(it[i-1].weight<=j)
    {


      dp[i][j]=max(dp[i-1][j],it[i-1].value+dp[i-1][j-it[i-1].weight]);
    }
    else
    {
      dp[i][j]= dp[i-1][j];
    }



    }




   }



  return dp[n][w];


   }



int main()
{

    int n,w;


      cin>>w;

      cin>>n;

      vector<item>it(n);


      for(int i=0;i<n;i++)
      {
         cin>>it[i].weight;

         cin>>it[i].value;



      }

   
   int mxVal=Knapsack(w,it);
      cout<<mxVal<<endl;


}
