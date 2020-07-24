bool isSafe(int i,int j,int m,int n){
    return i>=0 && i<m-1 && j>=0 && j<n-1;
}

void dfs(vector<vector<char>> &A,int i,int j,int m,int n){
    if(i<0 || i>=m || j<0 || j>=n)
        return;
    if(A[i][j]!='O')
        return;
    A[i][j] = '*';
    dfs(A,i-1,j,m,n);
    dfs(A,i+1,j,m,n);
    dfs(A,i,j-1,m,n);
    dfs(A,i,j+1,m,n);
}

void Solution::solve(vector<vector<char> > &A) {
    if(A.size() == 0)
        return;
    int m = A.size();
    int n = A[0].size();
    
    for(int i=0;i<m;i++){
        if(A[i][0] == 'O')
            dfs(A,i,0,m,n);
        if(A[i][n-1] == 'O')
            dfs(A,i,n-1,m,n);
    }
    for(int i=0;i<n;i++){
        if(A[0][i] == 'O')
            dfs(A,0,i,m,n);
        if(A[m-1][i] == 'O')
            dfs(A,m-1,i,m,n);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == 'O')
                A[i][j] = 'X';
            if(A[i][j] == '*')
                A[i][j] = 'O';
        }
    }
}
