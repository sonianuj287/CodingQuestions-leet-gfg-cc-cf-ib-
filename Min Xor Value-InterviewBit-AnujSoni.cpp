int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int res = A[1]^A[0];
    for(int i=0;i<A.size()-1;i++)
        res = min(res,A[i]^A[i+1]);
    return res;
}
