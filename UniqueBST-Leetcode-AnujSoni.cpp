class Solution {
public:
    unsigned long int combination(int a,int b){
        unsigned long int res = 1;
        if(b > a-b)  //c(n,k) == c(n,n-k)
            b = a-b;
        for(int i=0;i<b;i++){ //c(2*3, 3) == 6!/3!*3!
            res *= (a-i);
            res /= (i+1);
        }
        return res;
    }
    
    unsigned long int catalan(int n){
        unsigned long int c = combination(2*n,n);
        return c/(n+1);
    }
    
    int numTrees(int n) {
        return catalan(n);
    }
};
