int Solution::cntBits(vector<int> &A) {
    int len=A.size(),temp;
    
    long long int zero=0,one=0,x,sum=0;
    for(int i=0;i<32;i++)
    {   one=0,zero=0;
        
        x=1<<i;
        for(int j=0;j<len;j++)
        {
            
            if(x&A[j])
                one++;
            else
                zero++;
        }
        sum=(sum+(2*one*zero)%mod)%mod;
    }
    
    return sum;
}
