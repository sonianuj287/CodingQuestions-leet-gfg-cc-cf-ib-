class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        stack<int> s;
        int n = T.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && T[s.top()]<=T[i])
                s.pop();
            if(s.empty())
                res.push_back(0);
            if(!s.empty())
                res.push_back(s.top()-i);
            s.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
