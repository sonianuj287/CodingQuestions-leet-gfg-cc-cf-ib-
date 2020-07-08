class Solution {
public:
    vector<vector<string>> board;
    vector<string> temp;
    
    bool isSafe(int row,int col,int n){
        for(int i=0;i<col;i++)// checking row like-10,11,12,13
            if(temp[row][i]=='Q')
                return false;
        
        int x = row, y = col;
        while(x>=0 && y>=0){  //left bottom diagonal
            if(temp[x][y]=='Q')
                return false;
            x--;y--;
        }
        
        x = row, y = col;
        while(y>=0 && x<n){//right bottom diagonal
            if(temp[x][y]=='Q')
                return false;
            x++;y--;
        }
        return true;
    }
    
    bool solve(int col, int n){
        if(col >= n){
            board.push_back(temp);
            return false;
        }
        for(int i=0;i<n;i++){//checking every rows of chosen column
            if(isSafe(i,col,n)){
                temp[i][col] = 'Q';
                if(solve(col+1,n))
                    return true;
                temp[i][col] = '.';
            }
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string res(n,'.');
        temp.resize(n,res);
        solve(0,n); //sending column 0

        return board;
    }
};
