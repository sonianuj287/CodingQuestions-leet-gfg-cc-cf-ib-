class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size())
            return res;
                
        vector<int> scount(256,0);
        vector<int> pcount(256,0);
        
        
        int m = s.size();
        int n = p.size();
        
        for(int i=0;i<n;i++){
            pcount[p[i]]++;
            scount[s[i]]++;
        }
        for(int i=0;i<m-n+1;i++){
            if(scount == pcount)
                res.push_back(i);
            scount[s[i]]--;
            scount[s[i+n]]++;
        }
        return res;
    }
};
