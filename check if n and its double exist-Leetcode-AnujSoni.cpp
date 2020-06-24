class Solution {
public:
    bool checkIfExist(vector<int>& v) {
        sort(v.begin(),v.end());
        
        for(auto i=v.begin();i!=v.end();i++){
            if(*i>=0 && binary_search(i+1,v.end(),*i * 2))
                return true;
            if(*i<0 && binary_search(v.begin(),i,*i * 2))
                return true;
        }
        return false;
    }
};
