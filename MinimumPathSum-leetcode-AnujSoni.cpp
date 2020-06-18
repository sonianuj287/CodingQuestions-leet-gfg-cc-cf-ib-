class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        const int inf = 1e9+5;
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(i==0 && j==0)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = grid[i][j] + min ( (i==0?inf:dp[i-1][j]) , (j==0?inf:dp[i][j-1]) );
        }
        return dp[m-1][n-1];
    }
};
