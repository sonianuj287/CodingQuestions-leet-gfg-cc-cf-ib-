class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=0;i<pow(2, nums.size());i++){
            vector<int> v;
            for(int j=0;j<nums.size();j++){
                if((i&(1<<j))!=0)
                    v.push_back(nums[j]);
            }            
            res.push_back(v);
        }
        return res;
    }
};
//////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void generateSubset(int index,vector<int>& nums,vector<int>& v,vector<vector<int>>& res){
        if(index == nums.size())
            res.push_back(v);
        else{
            v.push_back(nums[index]);
            generateSubset(index+1,nums,v,res);
            v.pop_back();
            generateSubset(index+1,nums,v,res);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        generateSubset(0,nums,v,res);
        return res;
    }
};
