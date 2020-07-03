class Solution {
public:
    string lastSubstring(string s) {
        int a = 0;// position of last lex string so far
        int b = 1;// position of candidate substring
        for(int i=b;i<s.size();i++){
            if(s[i] != s[a + (i-b)]){
                a = (s[i]>s[a+(i-b)])?b:a;
                i=b;
                b++;
            }
        }
        return s.substr(a);
    }
};
