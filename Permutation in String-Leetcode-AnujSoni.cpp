class Solution {
public:    
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m > n)
            return false;
        
        vector<int> count1(256,0);
        vector<int> count2(256,0);

        for(int i=0;i<m;i++){
            count1[s1[i]]++;
            count2[s2[i]]++;
        }
        for(int i=0;i<=n-m;i++){
            if(count1 == count2)
                return true;
            count2[s2[i+m]]++;
            count2[s2[i]]--;
            
        }
        return false;
    }
};
