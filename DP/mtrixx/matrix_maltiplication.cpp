        //header
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
   const int mx=1e6;


   void printOptimalParenthesis(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i+1;
    } else {
        cout << "(";
           // cout<<"\n "<<i<<" "<< split[i][j]<<endl;
        printOptimalParenthesis(split, i, split[i][j]);
           //   cout<<"\n"<< split[i][j]+1<<" "<<j<<endl;
        printOptimalParenthesis(split, split[i][j] + 1, j);
        cout << ")";
    }
}

// Function to find the minimum number of scalar multiplications
// needed to multiply a chain of matrices and print the optimal parenthesized form
void matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> split(n, vector<int>(n, 0));

    // dp[i][j] will store the minimum number of scalar multiplications
    // needed to multiply matrices from i to j

    // Fill the table in a bottom-up manner
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k; // Store the optimal split position
                }
            }
        }
    }

    cout<<"\n";

   for(int i=0;i<n;i++)
   {
for(int j=0;j<n;j++)
{


  cout<<split[i][j]<<" ";

}
cout<<"\n";


   }

      cout<<"\n"<<dp[0][n-1]<<endl;
    // Reconstruct the optimal parenthesized form
    printOptimalParenthesis(split, 0, n - 1);
}

// Function to print the optimal parenthesized form


int main() {
    // Example usage
    vector<int> dimensions = {1 ,3 ,2 ,1, 5};
   
    matrixChainMultiplication(dimensions);

   
    return 0;
}
