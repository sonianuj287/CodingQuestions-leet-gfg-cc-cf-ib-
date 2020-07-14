class Solution {
public:
    void rec(set<vector<int>>& s,vector<int>& nums,int target,vector<int> v,int i){
        if(target == 0){
            s.insert(v);
            return;
        }
        if(i == nums.size())
            return;
        if(target - nums[i] >= 0){
            v.push_back(nums[i]);
            rec(s,nums,target-nums[i],v,i+1);
            v.pop_back();
        }
        else
            return;
        rec(s,nums,target,v,i+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        rec(s,candidates,target,v,0);
        for(auto x:s){
            res.push_back(x);
        }
        return res;
    }
};
