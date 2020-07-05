class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int l;
        int r;
        if(left.size()==0)
            l = INT_MIN;
        
        else{
            l = left[0];
            for(int i=1;i<left.size();i++)
                l = max(l,left[i]);
        }
        if(right.size()==0)
            r = INT_MIN;
        else{
            r = right[0];
            for(int i=1;i<right.size();i++)
                r = min(r,right[i]);
        }
        cout<<l<<" "<<r;
        if(l == INT_MIN)
            return n-r;
        if(r == INT_MIN)
            return l-0;
        return max(l-0,n-r);
            
    }
};
