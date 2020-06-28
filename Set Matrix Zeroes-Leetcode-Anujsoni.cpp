class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        int rowf = 0;
        int colf = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && matrix[i][j] == 0)
                    rowf = 1;
                if(j == 0 && matrix[i][j] == 0)
                    colf = 1;
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0)
                    matrix[i][j] = 0;
                if(matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(rowf == 1){
            for(int i=0;i<n;i++)
                matrix[0][i] = 0;
        }
        if(colf == 1){
            for(int i=0;i<m;i++)
                matrix[i][0] = 0;
        }
        
    }
};
