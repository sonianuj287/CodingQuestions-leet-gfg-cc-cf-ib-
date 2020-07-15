class Solution {
public:
    int area = 0;
    int maxarea = 0;
    bool isSafe(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(isSafe(i,j,m,n) && grid[i][j] == 1){
            area++;
            grid[i][j] = 0;
            dfs(i-1,j,m,n,grid);
            dfs(i+1,j,m,n,grid);
            dfs(i,j-1,m,n,grid);
            dfs(i,j+1,m,n,grid);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,m,n,grid);
                    if(area > maxarea)
                        maxarea = area;
                    area = 0;
                }
            }
        }
        return maxarea;
    }
};
