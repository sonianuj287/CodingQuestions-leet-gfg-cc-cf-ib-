class Solution {
public:
    int kadane(vector<int> A){
        int max_end_here = 0;
        int max_so_far = INT_MIN;
        for(int i=0;i<A.size();i++){
            max_end_here += A[i];
            if(max_so_far<max_end_here)
                max_so_far = max_end_here;
            if(max_end_here<0)
                max_end_here = 0;
        }
        return max_so_far;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int normal = kadane(A);
        if(normal<0)
            return normal;
        int arr_sum = 0;
        for(int i=0;i<A.size();i++){
            arr_sum += A[i];
            A[i] = -A[i];
        }
        int circular = arr_sum + kadane(A);
        return max(normal,circular);
    }
};
