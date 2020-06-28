// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

const int p = 1e9+7;

int nCrModp(int, int);

// Driver program 
int main() 
{ 
  int t, n, r;
  cin >> t;
  
  while(t--){
      cin >> n >> r;
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}
// } Driver Code Ends


// Returns nCr % p 
int nCrModp(int n, int r) 
{ 
    int dp[n+1][r+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=r;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            if(j>i)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%1000000007;
        }
    }
    return dp[n][r];
} 
