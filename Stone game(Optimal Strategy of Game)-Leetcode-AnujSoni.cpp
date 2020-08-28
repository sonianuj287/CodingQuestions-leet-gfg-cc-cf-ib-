class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        int dp[n][n];
        for(int i=0;i<n-1;i++)
            dp[i][i+1] = max(arr[i],arr[i+1]);
        for(int gap=3;gap<n;gap+=2){
            for(int i=0;i+gap<n;i++){
                int j = i+gap;
                dp[i][j] = max( arr[i] + min( dp[i+2][j],dp[i+1][j-1] ), arr[j] + min( dp[i+1][j-1],dp[i][j-2] ) );
            }
        }
        
        int s = 0;
        for(int i=0;i<arr.size();i++)
            s+=arr[i];
        int rem = s - dp[0][n-1];
        return dp[0][n-1]>rem;
    }
};
