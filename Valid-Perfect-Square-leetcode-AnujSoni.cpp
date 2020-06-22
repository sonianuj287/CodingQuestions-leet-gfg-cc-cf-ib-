class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int i=1;
        while(i*i<=num){
            i++;
        }
        i--;
        if(i*i == num)
            return true;
        else
            return false;
    }
};
