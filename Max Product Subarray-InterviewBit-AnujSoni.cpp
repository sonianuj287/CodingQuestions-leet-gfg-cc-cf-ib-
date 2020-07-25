class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cMax = 1;
        int cMin = 1;
        int max_so_far = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int pMax = nums[i]*cMax;
            int pMin = nums[i]*cMin;
            cMax = max({nums[i],pMax,pMin});
            cMin = min({nums[i],pMax,pMin});
            max_so_far = max(max_so_far,cMax);
        }
        return max_so_far;
    }
};
