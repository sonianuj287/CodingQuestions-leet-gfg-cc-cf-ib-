class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = 1;
        int curr_min = 1;
        int max_so_far = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int potential_max = nums[i]*curr_max;
            int potential_min = nums[i]*curr_min;
            curr_max = max({nums[i],potential_max,potential_min});
            curr_min = min({nums[i],potential_max,potential_min});
            max_so_far = max(max_so_far,curr_max);
        }
        return max_so_far;
    }
};
