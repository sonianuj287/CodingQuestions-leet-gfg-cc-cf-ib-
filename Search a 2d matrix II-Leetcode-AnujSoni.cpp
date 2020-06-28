/*
	The idea is simple start from the top right corner of the matrix 
	1. if the target is smaller than the present element at (i,j)
		 then it is also smaller than all the elements in the column j (because matrix is sorted coulmn wise also)
		 therefore we change the coulumn i.e j--;
	
	2. else if the target is greater than the present element at (i,j)
		 then it is also greater than all the elements in the row i (because matrix is sorted row wise also)
		 therefore we change the row i.e i++;
	
	3. else return true because we have found the element
	4. otherwise return false because target is not present

BELOW is the implementation of this illustration.

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(target < matrix[i][j])
                j--;
            else if(target > matrix[i][j])
                i++;
            else
                return true;
        }
        return false;
    }
};
