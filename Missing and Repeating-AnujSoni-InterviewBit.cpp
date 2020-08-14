vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long n = A.size();
    long s1 = 0;
    long s2 = 0;
    for(int i:A){
        s1 += (long)i;
        s2 += (long)i*i;
    }
    long e1 = n*(n+1) /2;
    long e2 = n*(n+1)*(2*n+1)/6;
    
    long d1 = s1-e1;
    long d2 = s2-e2;
    
    long dif = d1;
    long sum = d2/d1;
    
    long repeat = (sum+dif)/2;
    long miss = (sum-dif) /2;
    return {(int)repeat,(int)miss};
}
