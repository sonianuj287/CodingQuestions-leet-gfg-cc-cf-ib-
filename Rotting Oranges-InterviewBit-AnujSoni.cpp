class Solution {
public:
    bool isSafe(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int orangesRotting(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        if(m == 0 || n == 0)
            return 0;
        if(m == 1 && n == 1 && A[0][0] == 1)
            return -1;
        if(m == 1 && n == 1)
            return 0;
        int total = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j] == 1 || A[i][j] == 2)
                    total++;
                if(A[i][j] == 2)
                    q.push(make_pair(i,j));
            }
        }
        int cnt=0,tm=0;
        while(!q.empty()){
            cnt += q.size();
            int s = q.size();
            while(s--){
                pair<int,int> x = q.front();
                q.pop();
                int i = x.first;
                int j = x.second;
                if(isSafe(i+1,j,m,n) && A[i+1][j] == 1){
                    A[i+1][j] = 2;
                    q.push(make_pair(i+1,j));
                }
                if(isSafe(i-1,j,m,n) && A[i-1][j] == 1){
                    A[i-1][j] = 2;
                    q.push(make_pair(i-1,j));
                }
                if(isSafe(i,j-1,m,n) && A[i][j-1] == 1){
                    A[i][j-1] = 2;
                    q.push(make_pair(i,j-1));
                }
                if(isSafe(i,j+1,m,n) && A[i][j+1] == 1){
                    A[i][j+1] = 2;
                    q.push(make_pair(i,j+1));
                }
            }
            tm++;
        }
        if(cnt == total)
            return tm-1;
        return -1;
    }
};
