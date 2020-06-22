bool cmp(vector<int> a,vector<int> b){
    int x = a[0]*a[0] + a[1]*a[1];
    int y = b[0]*b[0] + b[1]*b[1];
    return x<y;
}

class Solution {
public: 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),cmp);
        int n = points.size();
        vector<vector<int>> res;
        for(int i=0;i<K;i++)
            res.push_back(points[i]);
        return res;
    }
};
