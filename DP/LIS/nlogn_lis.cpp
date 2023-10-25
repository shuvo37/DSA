		//header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

int main(){
 

   vector<int>v;

   int n,num;

      cin>>n;

      for(int i=0;i<n;i++)
      {

        cin>>num;


         auto it=lower_bound(v.begin(),v.end(),num);

         if(v.end()==it)
         {

          v.push_back(num);

         }

   
         else
         	{


             v[it-v.begin()]=num;



         	}


      }


     cout<<v.size()<<endl;


}