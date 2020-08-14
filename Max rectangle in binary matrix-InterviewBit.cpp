int histogram(vector<int> heights){
    int n = heights.size();
    stack<int> s;
    int res = 0;
    for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            int t = s.top();
            s.pop();
            int curr = heights[t] * (s.empty()?i:i-s.top()-1);
            res = max(curr,res);
        }
        s.push(i);
    }
    while(!s.empty()){
        int t = s.top();
        s.pop();
        int curr = heights[t] * (s.empty()?n:n-s.top()-1);
        res = max(curr,res);
    }
    return res;
}
 
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<int> dp(n);
    int res = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0)
                dp[j] = A[i][j];
            else{
                if(A[i][j] == 0)
                    dp[j] = 0;
                else
                    dp[j] += 1;
            }
        }
        res = max(res,histogram(dp));
    }
    return res;
}
