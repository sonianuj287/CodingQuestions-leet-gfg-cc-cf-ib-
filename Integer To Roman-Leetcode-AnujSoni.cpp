class Solution {
public:
    string intToRoman(int num) {
        vector<string> numerals = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        string res="";
        int i=0;
        while(num>0){
            if(num-values[i] >=0){
                num = num-values[i];
                res+=numerals[i];
            }else{
                i++;
            }
        }
        return res;
    }
};
