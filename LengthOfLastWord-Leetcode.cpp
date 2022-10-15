class Solution {
public:
    string trim(string s){
        if(s[0] == ' '){
            int l = 1;
            for(int i=1;i<s.size();i++){
                if(s[i] == ' ')
                    l++;
                else
                    break;
            }
            s = s.substr(l, s.size()-l);
        }
        return s;
    }
    
    
    int lengthOfLastWord(string s) {
        s = trim(s);
        reverse(s.begin(), s.end());
        s = trim(s);
        reverse(s.begin(), s.end());
        int a = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ')
                a = i;
        }
        if(a == 0)
            return s.size();
        return s.size()-a-1;
    }
};
