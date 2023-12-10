
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e5;
   int n;
   int arr[mx+2];


    void mergee(int lo,int mid,int hi)
    {

      int tmp[mx];
      int i=lo,j=mid+1,k=lo;

      while(i<=mid&&j<=hi)
      {

        if(arr[j]<=arr[i])
        {

           tmp[k]=arr[j];
            j++;
        }
        else
        {

          tmp[k]=arr[i];
            i++;
        }

        k++;

      }



      while(i<=mid)
      {

        tmp[k++]=arr[i];
        i++;

      }

      while(j<=hi)
       {
        tmp[k++]=arr[j];
         j++;

       }



      for(i=lo;i<=hi;i++)
      {
         arr[i]=tmp[i];

      }



      }









  void  sortt(int lo,int hi)
   {

         if(lo>=hi){return;}

         int mid=(hi+lo)/2;

          sortt(lo,mid);
          sortt(mid+1,hi);

            mergee(lo,mid,hi);

   }





int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];

    }


     sortt(1,n);

     for(int i=1;i<=n;i++)
    {
      cout<<arr[i]<<" ";

    }


}
