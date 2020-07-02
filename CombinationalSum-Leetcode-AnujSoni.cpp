class Solution {
public:
    void rec(vector<int>& candidates, int target,vector<vector<int>>& res,vector<int>& v,int i){
        if(target<0)
            return;
        if(target == 0){
            res.push_back(v);
            return;
        }
        while(i<candidates.size() && target - candidates[i] >= 0){
            v.push_back(candidates[i]);
            rec(candidates,target-candidates[i],res,v,i);
            i++;
            v.pop_back();
        }
            
    }
    
    vector<vector<int>> combinationSum(vector<int>& ar, int target) {
        sort(ar.begin(),ar.end());
        ar.erase(unique(ar.begin(), ar.end()), ar.end());
        vector<vector<int>> res;
        vector<int> v;
        rec(ar,target,res,v,0);
        return res;
    }
};
