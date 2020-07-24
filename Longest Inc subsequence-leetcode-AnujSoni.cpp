class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i] = 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int m = dp[0];
        for(int i=1;i<n;i++)
            m = max(m,dp[i]);
        return m;
    }
};
