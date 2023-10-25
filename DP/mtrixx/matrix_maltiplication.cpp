		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

int main(){
 
  int n=5;

  int p[]={5,4,6,2,7};
  int m[5][5]={0};
  int s[5][5]={0};

  int j,mi,q;

  for(int d=1;d<n-1;d++)
  {

  for(int i=1;i<n-d;i++)
  {


  q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];

    if(q<mi)  j=i+d;
  mi=32767;
  for(int k=i;k<=j-1;k++)
  {


    {

   mi=q;
   s[i][j]=k;


    }


  }


m[i][j]=mi;


  }


  }  
cout<<m[i][n-1];

}