class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string res="";
        int i = 0;
        while(i<=s.size()){
            if(isdigit(s[i])){
                int count=0;
                while(isdigit(s[i]))
                    count = count*10 + s[i++]-'0';
                counts.push(count);
                
            }
            else if(s[i] == '['){
                result.push(res);
                res = "";
                i++;                
            }
            else if(s[i] == ']'){
                string temp = result.pop();
                int count = counts.pop();
                for(int j=0;j<count;j++)
                    temp+=res;
                res = temp.to_string();
                i++;
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};
