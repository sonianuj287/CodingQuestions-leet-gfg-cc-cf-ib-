class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)
            return "";
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int max_len = 0, start = 0;
        
        for(int i=0;i<n;i++)
            dp[i][i] = true;
        
        max_len = 1, start = 0;
        
        for(int k=1;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j = i+k;
                if(j-i+1 == 2 && s[i] == s[j])
                    dp[i][j] = true;
                else
                    if(s[i] == s[j] && dp[i+1][j-1])
                        dp[i][j] = true;  
                if(dp[i][j] && max_len < j-i+1)
                    max_len = j-i+1, start = i;
            }
        }
        return s.substr(start,max_len);
    }
};
