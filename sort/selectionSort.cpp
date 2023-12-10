		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

int main(){
  
    int n=5;
      //cin>>n;
        int a[n]={-2,-3,-4,-5,-6};
      /*  for(int i=0;i<n;i++){

        	 cin>>a[i];
        }*/
       
    
        for(int i=0;i<n-1;i++){

        	 int min=i;

        for(int j=i+1;j<n;j++){


              if(a[min]>a[j]){


                   min=j;

              }


        }

        swap(a[min],a[i]);

        }

         for(int i=0;i<n;i++){

        	 cout<<a[i]<<" ";
        }




}