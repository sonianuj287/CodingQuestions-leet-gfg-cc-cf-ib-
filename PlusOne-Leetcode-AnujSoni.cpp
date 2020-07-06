class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 0){
            digits.push_back(1);
            return digits;
        }
        if(digits[n-1]<9){
            digits[n-1]+=1;
            return digits;
        }
        int a = 0;
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]+=1;
                return digits;
            }
            digits[i] = 0;
            a++;
        }
        if(a == digits.size()){
            vector<int> res;
            res.push_back(1);
            for(int i=0;i<a;i++)
                res.push_back(0);
            return res;
        }
        return digits;
    }
};
