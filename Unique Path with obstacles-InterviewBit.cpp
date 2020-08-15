int Solution::uniquePathsWithObstacles(vector<vector<int> > &obg) {
            int m = obg.size();
        int n = obg[0].size();
        // int dp[m][n];
        if(obg[0][0] == 1)
            return 0;
        else
            obg[0][0] = 1;
        for(int i=1;i<m;i++){
            if(obg[i][0] == 1)
                obg[i][0] = 0;
            else
                obg[i][0] = obg[i-1][0];
        }
        for(int i=1;i<n;i++){
            if(obg[0][i] == 1)
                obg[0][i] = 0;
            else
                obg[0][i] = obg[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obg[i][j] == 1)
                    obg[i][j] = 0;
                else
                    obg[i][j] = obg[i-1][j] + obg[i][j-1];
            }
        }
        return obg[m-1][n-1];
}
