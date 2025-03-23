 bool vis[mx][mx];

  int r1 , r2 , c1 , c2;


  int dx[]= {1 , -1 , 0 , 0};

  int dy[]= {0 , 0 , 1 , -1};

   bool is_Valid(int r , int c )
   {


   if(r <= n && c <= m  && r >=1 && c >= 1 && !vis[r][c] && s[r-1][c-1] != '1')
   {


       return true;


   }


   return false;


   }



     void dfs(int r , int c , int val)
     {


        vis[r][c] = true;

         arr[r][c] = val;


      for(int i = 0; i<4; i++)
      {

          if(is_Valid(r+dx[i] , c + dy[i]))
          {

            int x = r+dx[i];
            int y = c + dy[i];



            dfs(x , y , val);

          }


      }




     }
