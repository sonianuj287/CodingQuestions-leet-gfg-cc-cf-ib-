bool cmp(const vector<int>& i, const vector<int>& j) {
    return (i[1] - i[0]) < (j[1] - j[0]);
}

class Solution {
public:    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int total = 0;
        for(int i=0;i<costs.size();i++){
            if(i<costs.size()/2)
                total += costs[i][1];
            else
                total += costs[i][0];
        }
        return total;
    }
};
