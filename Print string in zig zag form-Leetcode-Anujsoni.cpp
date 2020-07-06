class Solution {
public:
    string convert(string s, int k) {
        if(k == 0)
            return s;
        if(k == 1)
            return s;
        string res="";
        //print first row
        for(int i=0;i<s.length();i+=(k-1)*2)
            res += s[i];
        //print mid row
        for(int j=1;j<k-1;j++){
            bool down = true;
            for(int i=j;i<s.length();){
                res += s[i];
                if(down)
                    i += (k-j-1)*2;
                else
                    i += (k-1)*2 - (k-j-1)*2;
                down = !down;
            }
        }
        //print last row
        for(int i=k-1;i<s.length();i+=(k-1)*2)
            res += s[i];
        return res;
    }
};
