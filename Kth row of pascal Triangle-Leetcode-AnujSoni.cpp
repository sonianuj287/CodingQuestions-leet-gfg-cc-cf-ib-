class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); 
        for(int i=0;i<n+1;i++)
            dp[i][0] = 1;
        for(int i=0;i<n+1;i++)
            dp[i][i] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(i>=j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n+1;i++)
            res.push_back(dp[n][i]);
        return res;
    }
};
