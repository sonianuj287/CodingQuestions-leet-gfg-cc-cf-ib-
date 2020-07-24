class Solution {
public:
    int histogram(vector<int> dp){
        int n = dp.size();
        stack<int> s;
        int res=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && dp[s.top()]>=dp[i]){
                int t = s.top();
                s.pop();
                int curr = dp[t] * (s.empty()?i:(i-s.top()-1));
                res = max(curr,res);
            }
            s.push(i);
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            int curr = dp[t] * (s.empty()?n:(n-s.top()-1));
            res = max(curr,res);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        vector<int> dp(matrix[0].size());
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i == 0){
                    dp[j] = matrix[i][j] - '0';
                }
                else{
                    if(matrix[i][j] == '0')
                        dp[j] = 0;
                    else
                        dp[j] += 1;//if matrix is not binary, push the number instead of 1; dp[j] += matrix[i][j]-'0'
                }
            }
            ans = max(ans,histogram(dp));
        }
        return ans;
    }
};
