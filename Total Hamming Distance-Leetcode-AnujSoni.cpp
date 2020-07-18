class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<32;i++){
            int c = 0;
            for(int j=0;j<nums.size();j++){
                if((1<<i)&nums[j])
                    c++;
            }
            res += (nums.size()-c)*c;
        }
        return res;
    }
};
