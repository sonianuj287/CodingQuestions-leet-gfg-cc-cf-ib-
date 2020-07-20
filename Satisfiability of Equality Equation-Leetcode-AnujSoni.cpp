class Solution {
public:
    int uf[26];
    
    int find(int x) {
        if (x != uf[x]) 
            uf[x] = find(uf[x]);
        return uf[x];
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();
        for(int i=0;i<26;i++)
            uf[i] = i;
        
        for(string s:equations){
            if(s[1] == '=')
                uf[find(s[0]-'a')] = find(s[3]-'a');
        }
        
        for(string e:equations){
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                    return false;
        }
        return true;
    }
};
