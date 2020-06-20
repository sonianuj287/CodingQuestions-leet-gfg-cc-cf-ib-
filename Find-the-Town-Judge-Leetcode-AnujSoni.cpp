class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0){
            if(N==1)
                return 1;
            return -1;
        }
        
        vector<int>p(N+1,0);
        for(int i=0;i<trust.size();i++){
            p[trust[i][1]]++;
            p[trust[i][0]]--;
        }
        for(int i=1;i<=N;i++){
            if(p[i] == N-1){
                return i;
            }
        }
        return -1;
    }
};
