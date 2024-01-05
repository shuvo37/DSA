        //header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=100;

     vector<int>place(mx);

      int n;

 bool is_valid(int row,int col)
 {

  for(int p_row=0;p_row<row;p_row++)
  {

    int pre_col=place[p_row];
     if(pre_col==col||abs(p_row-row)==abs(col-pre_col))
     {


       return false;

     }





  }

 return true;

 }


void  n_queen(int row)
 {


  if(row==n)
    {

   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     {


      if(place[i]==j)
      {
         cout<<"Q";
      }
      else{
          cout<<".";
      }


     }
       cout<<"\n";
   }

    cout<<"\n";
   return;

    }
   

  for(int col=0;col<n;col++)
  {


    if(is_valid(row,col))
    {

    place[row]=col;

      n_queen(row+1);


    }



  }




 }








int main(){
 


  cin>>n;



  n_queen(0);




}