class Solution {
public:
    int digitsum(int n){
        int total = 0;
        while(n){
            int t = n%10;
            n = n/10;
            total += t;
        }
        return total;
    }
    
    int countLargestGroup(int n) {
        map<int,int> m;
        for(int i=1;i<=n;i++)
            m[digitsum(i)]++;
        int maxlen = 0;
        int cnt = 0;
        for(auto i=m.begin();i!=m.end();i++)
            maxlen = max(maxlen,i->second);
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second == maxlen)
                cnt++;
        }
        return cnt;
    }
};
