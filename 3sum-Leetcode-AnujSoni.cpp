class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i == 0 || (i>0 && nums[i] != nums[i-1])){
                int j = i+1,k=nums.size()-1;
                while(j<k){
                    int s = nums[i]+nums[j]+nums[k];
                    if(s == 0){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        res.push_back(t);
                        t.clear();
                        while(j<k && nums[j] == nums[j+1]) j++;
                        while(j<k && nums[k] == nums[k-1]) k--;
                        j++;
                        k--;
                    }
                    else if(s < 0)
                        j++;
                    else
                        k--;
                }
            }
        }
        return res;
    }
};
