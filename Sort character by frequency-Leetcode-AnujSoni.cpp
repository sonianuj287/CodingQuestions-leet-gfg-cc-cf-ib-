// bool cmp(pair<char,int> p1,pair<char,int> p2){
//     if(p1.second != p2.second)
//         return p1 > p2;
//     return p1.first < p2.first;
// }

class Solution {
public:
    string frequencySort(string s) {
        // unordered_map<char,int> m;
        // for(int i=0;i<s.size();i++)
        //     m[s[i]]++;
        // vector<pair<char,int>> v;
        // for(auto i=m.begin();i!=m.end();i++)
        //     v.push_back(make_pair(i->first,i->second));
        // sort(v.begin(),v.end(),cmp);
        // string res;
        // for(auto i=v.begin();i!=v.end();i++){
        //     while(i->second--)
        //         res += i->first;
        // }
        // reverse(res.begin(),res.end());
        // return res;
        
        string ans = "";
        unordered_map<char,int> m;
        for(char c:s)
            m[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto i:m)
            pq.push(make_pair(i.second,i.first));
        pair<int,char> p;
        while(!pq.empty()){
            p = pq.top();
            pq.pop();
            for(int i=0;i<p.first;i++)
                ans += p.second;
        }
        return ans;
    }
};
