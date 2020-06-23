class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        bool odd = false;
        while(l<r){
            int mid = l + (r-l) /2;
            odd = (r-mid)%2!=0; //if right is contains odd
            if(nums[mid-1] == nums[mid]){
                if(odd)
                    l = mid+1;
                else
                    r = mid-2;
            }
            else if(nums[mid+1] == nums[mid]){
                if(odd)
                    r = mid-1;
                else
                    l = mid+2;
            }
            else
                return nums[mid];
        }
        return nums[l];
    }
};
