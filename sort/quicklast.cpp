
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5;
    int arr[mx];


   int partition(int lo,int hi)
   {

       int pivot=arr[hi];

       int i=lo;
       int j=hi-1;


         while(1)
         {

           while(i<=j&&arr[i]<=pivot){i++;}
           while(i<=j&&arr[j]>pivot){j--;}
            if(i<=j){swap(arr[i],arr[j]);}else {break;}
         }


         swap(arr[i],arr[hi]);

       return i;

   }



    void quick(int l,int r)
    {

       if(l>=r){return;}

        int mid=partition(l,r);
         quick(l,mid-1);
         quick(mid+1,r);

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

}
