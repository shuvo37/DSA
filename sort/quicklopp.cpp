
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5;
    int arr[mx+2];

   int cnt=0;


    int partition(int lo,int hi)
    {
      cnt++;
      int indx=lo-1;
      int p=arr[hi];

       for(int i=lo;i<hi;i++)
       {

            if(p>arr[i])
           {
              indx++;
              swap(arr[i],arr[indx]);


           }


       }

        indx++;
      swap(arr[indx],arr[hi]);

      return indx;

    }






    void quick(int lo,int hi)
    {
         cnt++;

         if(lo>=hi){return;}

       int mid=partition(lo,hi);

         quick(lo,mid-1);


         quick(mid+1,hi);

    }



int main(){


    int n;
    cin>>n;

     for(int i=1;i<=n;i++)
     {
       cin>>arr[i];

     }

  quick(1,n);

  for(int i=1;i<=n;i++)
  {
      cout<<arr[i]<<" ";
  }
   cout<<"\n";
  cout<<cnt<<endl;
}
