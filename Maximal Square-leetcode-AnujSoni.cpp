class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int answer = 0;
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '1'){
                    dp[i][j] = 1;
                    if(i>0 && j>0)
                        dp[i][j] += min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                    answer = max(answer,dp[i][j]);
                }
            }
        }
        return answer*answer;
    }
};
