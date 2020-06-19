class Solution {
public:
    int hIndex(vector<int>& citations) {
        //0,1,3,5,6
        //is their atleast 6 no. greater than 6? no
        //is their atleast 5 no. greater than 5? no
        //is their atleast 4 no. greater than 4? no
        //is their atleast 3 no. greater than 3? yes
        //so 3 will be the answer;
        
        int n = citations.size();
        if(!n) 
            return 0;
        int low = 0, high = n-1;
        int ans = 0;
        while(low<=high){  //binary search
            int mid = low + (high-low) /2;
            if(citations[mid] >= n-mid){
                ans = n-mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
