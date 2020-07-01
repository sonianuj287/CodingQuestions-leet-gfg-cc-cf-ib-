class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        int pr = 0;
        while(n>0){
            pr = i;
            n = n-i;
            i++;
        }
        if(n!=0)
            return pr-1;
        return pr;
    }
};
