class Solution {
public:
    static inline int dist(int a1, int a2) {
        return (a1 - a2) * (a1 - a2);
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x_closest;
        int y_closest;
        if(x_center > x1 && x_center < x2)
            x_closest = x_center;
        else
            x_closest = abs(x1-x_center) < abs(x2-x_center) ? x1:x2;
        
        if(y_center > y1 && y_center < y2)
            y_closest = y_center;
        else
            y_closest = abs(y1-y_center) < abs(y2-y_center) ? y1:y2;
        
        return dist(x_closest, x_center) + dist(y_closest, y_center) <= radius * radius;

    }
};
