class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        if(n == 0)
            return 1;
        int flag = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1)
                flag = 1;
            else if(nums[i]<=0 || nums[i]>n)
                nums[i] = 1;
        }
        if(flag == 0)
            return 1;
        
        for(int i=0;i<n;i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
                nums[index] = -1 * nums[index];
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};
