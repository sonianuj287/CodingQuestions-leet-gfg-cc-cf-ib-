class Solution {
public:
    int countPrimes(int n) {
        if(n == 0)
            return 0;
        bool prime[n];
        memset(prime,true,sizeof(prime));
        for(int p=2;p*p<n;p++){
            if(prime[p]==true){
                for(int i=p*p;i<n;i+=p)
                    prime[i] = false;
            }
        }
        int total=0;
        for(int i=2;i<n;i++)
            if(prime[i])
                total++;
        return total;
    }
};
