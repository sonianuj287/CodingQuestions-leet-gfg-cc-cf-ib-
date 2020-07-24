class Solution {
public:
    void dfs(int s,int d,vector<vector<int>>& graph,vector<int>& v,vector<vector<int>> &res){
        v.push_back(s);
        if(s == d){
            res.push_back(v);
            v.pop_back();
            return;
        }
        for(auto x:graph[s])
            dfs(x,d,graph,v,res);
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<int> v;
        dfs(0,n-1,graph,v,res);
        return res;
    }
};
