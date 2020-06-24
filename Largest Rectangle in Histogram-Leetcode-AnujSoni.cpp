class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int res=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                int t = s.top();
                s.pop();
                int curr = heights[t] * (s.empty()?i:(i-s.top()-1));
                res = max(curr,res);
            }
            s.push(i);
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            int curr = heights[t] * (s.empty()?n:(n-s.top()-1));
            res = max(curr,res);
        }
        return res;
    }
};
