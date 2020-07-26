class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr=0;
        int maxTillNow=0;
        for(int i=0;i<n;i++){
            maxTillNow = max(maxTillNow,i+nums[i]);
            if(i == curr){
                if(i<n-1)
                    ans++;
                curr = maxTillNow;
            }
        }
        return ans;
    }
};
