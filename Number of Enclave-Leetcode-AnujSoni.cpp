class Solution {
public:
    bool isSafe(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    void dfs(int i,int j,vector<vector<int>>& A){
        if(isSafe(i,j,A.size(),A[0].size()) && A[i][j] == 1){
                A[i][j] = 0;
                dfs(i-1,j,A);
                dfs(i+1,j,A);
                dfs(i,j-1,A);
                dfs(i,j+1,A);
        }
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for(int i=0;i<m;i++){
            if(A[i][0] == 1)
                dfs(i,0,A);
            if(A[i][n-1] == 1)
                dfs(i,n-1,A);
        }
        for(int i=0;i<n;i++){
            if(A[0][i] == 1)
                dfs(0,i,A);
            if(A[m-1][i] == 1)
                dfs(m-1,i,A);
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<A[i][j]<<" ";
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans += A[i][j];
        }
        return ans;
    }
};
