		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;
  
      
   

       void countsort(int a[],int n){
         int range=10;
          int output[n+1];   
            int count[range];
              memset(count,0,range);
           
          for(int i=0;i<n;i++){

              count[a[i]]++;
           }
           
           
           for(int i=0;i<range;i++){

           	  count[i]+=count[i-1];
           }
           
       
       for (int i = 0; a[i]; ++i) {
        output[count[a[i]] - 1] = a[i];
        --count[a[i]];
    }
        for (int i = 0;i<n; ++i)
        a[i] = output[i];


       for(int i=0;i<n;i++){

       	  cout<<a[i]<<" ";
       }

        }

int main(){
 

      int n;
      cin>>n;
       int a[n+2];
     for(int i=0;i<n;i++){

     	  cin>>a[i];
     	  
     }


        countsort(a,n);


}