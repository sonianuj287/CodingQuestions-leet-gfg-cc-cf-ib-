class Solution {
public:
    void trim(string& s){
        int i=0;
        while(s[i]==' ')
            i++;
        s = s.substr(i);
        reverse(s.begin(),s.end());
        i=0;
        while(s[i]==' ')
            i++;
        s = s.substr(i);
        reverse(s.begin(),s.end());
    }
    
    string reverseWords(string s) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
        if(s.length() == 0)
            return s;
        int flag = 0;
        for(int i=0;i<s.length();i++)
            if(s[i] != ' ')
                flag = 1;
        if(flag == 0)
            return "";
        trim(s);
        vector<string> v;
        
        string m="";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && s[i] == s[i-1])
                continue;
            m += s[i];
        }
        s = m;
        
        stringstream temp(s);
        string intermediate;
        while(getline(temp,intermediate,' '))
            v.push_back(intermediate);
        
        
        reverse(v.begin(),v.end());
        string res;
        for(int i=0;i<v.size();i++){
            res+=v[i];
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};
