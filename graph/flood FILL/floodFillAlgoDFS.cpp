
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;

    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
      int val=3;
    int gd[100][100],fgd[100][100];
     int n;
     int color[100][100];
     int stRow=1,stCol=0;
      bool isValid(int row,int col)
      {

        if((row>=0&&row<n)&&(col>=0&&col<n)&&(color[row][col]==0)&&(gd[row][col]==gd[stRow][stCol]))
        {


            return true;
        }


        return false;

      }

   void dfs(int r,int col)
   {

         color[r][col]=1;

          fgd[r][col]=val;


         for(int i=0;i<4;i++)
         {

           if(isValid(r+dx[i],col+dy[i]))
           {

              dfs(r+dx[i],col+dy[i]);

           }


         }


    color[r][col]=2;

   }





int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

       cin>>n;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {


            cin>>gd[i][j];
            fgd[i][j]=gd[i][j];


        }


      }

     memset(color,0,sizeof(color));

      dfs(1,0);

   cout<<" ans grid"<<endl;
      for(int i=0;i<n;i++)
      {

          for(int j=0;j<n;j++)
          {

              cout<<fgd[i][j]<<" ";
          }

          cout<<"\n";
      }

    /*  cout<<"color"<<endl;

         for(int i=0;i<n;i++)
      {

          for(int j=0;j<n;j++)
          {

              cout<<color[i][j]<<" ";
          }

          cout<<"\n";
      }*/





}
