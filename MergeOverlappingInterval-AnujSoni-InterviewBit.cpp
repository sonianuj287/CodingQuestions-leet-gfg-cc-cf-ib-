bool cmp(Interval a,Interval b){
    if(a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),cmp);
    int n =A.size();
    vector<Interval> ans;
    Interval toadd;
    int maxend = INT_MIN;
    for(int i=0;i<n;i++){
        if(A[i].start > maxend)
            toadd.start = A[i].start;
        maxend = max(maxend,A[i].end);
        if(i == n-1 or A[i+1].start > maxend){
            toadd.end = maxend;
            ans.push_back(toadd);
        }
    }
    return ans;
}
