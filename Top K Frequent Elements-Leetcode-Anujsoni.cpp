bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second != p2.second)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        vector<pair<int,int>> v;
        for(auto i=m.begin();i!=m.end();i++){
            v.push_back(make_pair(i->first,i->second));
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> v1;
        for(int i=0;i<v.size();i++){
            while(v[i].second--)
                v1.push_back(v[i].first);
        }
        vector<int> ::iterator ip;
        ip = unique(v1.begin(),v1.end());
        v1.resize(distance(v1.begin(),ip));
        v1.resize(distance(v1.begin(),v1.begin()+k));
        return v1;
    }
};
