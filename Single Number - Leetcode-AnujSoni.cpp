class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int c = 0;
        for(int i=0;i<nums.size();i++)
            c = c^nums[i];
        
        c = c&(~(c-1));
        int x = 0,y=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&c)
                x^=nums[i];
            else
                y^=nums[i];
        }
        return {x,y};
    }
};
