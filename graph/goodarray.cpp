		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
  

   int t;
    cin>>t;
    while(t--){
    int n,k;


   cin>>n>>k;


  int ans=((n+(k-1))/k);
     

  if(n%k>1 or (n%k==0 and k>1))
  {


    ans++;



  }

  cout<<ans<<endl;




}


}