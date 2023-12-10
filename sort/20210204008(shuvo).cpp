#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5;
    int arr[mx];
      int cnt[mx];

   int partition(int lo,int hi)
   {

     int idx=lo,cnt1=0;
      for(int i=lo;i<=hi;i++)
      {
         cnt[arr[i]]++;

           if(cnt[arr[i]]>cnt1)
           {

             idx=i;
             cnt1=cnt[arr[i]];

           }

      }

      swap(arr[lo],arr[idx]);

       int pivot=arr[lo];

       int i=lo+1;
       int j=hi;


         while(1)
         {

           while(i<=j&&arr[i]<=pivot){i++;}
           while(i<=j&&arr[j]>pivot){j--;}
            if(i<=j){swap(arr[i],arr[j]);}else {break;}
         }


         swap(arr[j],arr[lo]);

       for(int i=lo;i<=hi;i++)
       {
           cnt[arr[i]]=0;
       }


       return j;

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
