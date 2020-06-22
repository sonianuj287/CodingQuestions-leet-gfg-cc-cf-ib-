class Solution {
public:
    // int editDistance(string word1,string word2,int m,int n){
    //     if(m == 0) return n;
    //     if(n == 0) return m;
    //     if(word1[m-1] == word2[n-1])
    //         return editDistance(word1,word2,m-1,n-1);
    //     else
    //         return 1+min({editDistance(word1,word2,m,n-1),editDistance(word1,word2,m-1,n),editDistance(word1,word2,m-1,n-1)});
    // }
    
    int editDistance(string word1,string word2,int m,int n){
        int dp[m+1][n+1];
        dp[0][0] = 0;
        for(int i=1;i<=m;i++)
            dp[i][0] = i;
        for(int j=1;j<=n;j++)
            dp[0][j] = j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return editDistance(word1,word2,m,n);
    }
};
