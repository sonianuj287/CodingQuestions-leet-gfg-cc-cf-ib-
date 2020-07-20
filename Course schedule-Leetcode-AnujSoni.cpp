class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        int count = 0;
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
        }
        stack<int> s;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i] == 0)
                s.push(i);
        }
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            count++;
            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i][1] == curr){
                    inDegree[prerequisites[i][0]]--;
                    if(inDegree[prerequisites[i][0]] == 0)
                        s.push(prerequisites[i][0]);
                }
            }
        }
        return count == numCourses;
    }
};
