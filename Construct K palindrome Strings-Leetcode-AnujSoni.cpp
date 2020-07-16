class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k)
            return false;
        map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        int dist = 0;
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second %2 != 0)
                dist++;
        }
        if(dist <= k)
            return true;
        return false;
    }
};
