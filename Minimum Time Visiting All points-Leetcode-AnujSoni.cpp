class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int m = points.size();
        int a = points[0][0];
        int b = points[0][1];
        int sec = 0;
        for(int i=1;i<m;i++){
            sec += max( abs(points[i][0]-a),abs(points[i][1]-b));
            a = points[i][0];
            b = points[i][1];
        }
        return sec;
    }
};
