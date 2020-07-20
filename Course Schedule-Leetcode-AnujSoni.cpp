class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> mp;
        
        for(int i=0;i<prerequisites.size();i++)
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> indegree(numCourses,0);
        
        for(auto x:mp)
            for(auto y:x.second)
                indegree[y]++;
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++)
            if(indegree[i] == 0)
                q.push(i);
        
        vector<int> res;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto x:mp[curr]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        if(res.size() != numCourses)
            return {};
        return res;
    }
};
