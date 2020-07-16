class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int maxsat = 0;
        int res = 0;
        
        for(int k = 0;k<sat.size();k++){
        int i = k,j = 1;
        while(i<sat.size() && j<=sat.size()){
            maxsat += sat[i] * j;
            i++,j++;
        }
        if(maxsat > res)
            res = maxsat;
        maxsat = 0;
        }
        
        return res;
    }
};
