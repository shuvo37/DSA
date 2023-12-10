#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5;
     int arr[mx];
     int n;

   void  insertion()
   {

     for(int i=1;i<=n;i++)
     {

         int x=arr[i];
         int j=i-1;

         while(j>=1&&x<arr[j])
         {
             arr[j+1]=arr[j];
             j--;

         }

         arr[j+1]=x;

     }




   }


int main(){




  cin>>n;
  for(int i=1;i<=n;i++)
  {

    cin>>arr[i];

  }

    insertion();

   for(int i=1;i<=n;i++)
   {
    cout<<arr[i]<<" ";

   }
   cout<<"\n";

}
