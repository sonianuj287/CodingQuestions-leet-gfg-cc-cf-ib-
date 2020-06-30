class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<indices.size();i++){
            int a = indices[i][0];
            int b = indices[i][1];
            for(int j=0;j<m;j++)
                mat[a][j] += 1;
            for(int j=0;j<n;j++)
                mat[j][b] += 1;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(mat[i][j]%2 != 0)
                    count++;
        }
        return count;
    }
};
