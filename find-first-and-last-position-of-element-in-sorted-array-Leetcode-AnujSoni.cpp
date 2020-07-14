class Solution {
public:
    int binarysearch(vector<int> v,int t,bool left){//extreme left
        int i = 0,j = v.size();
        while(i<j){
            int m = (i+j) / 2;
            if(v[m] > t || (left && t == v[m]))
                j = m;
            else
                i = m+1;
        }
        return i;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        int lidx = binarysearch(nums,target,true);//for left
        if(lidx == nums.size() || nums[lidx] != target)
            return v;
        v[0] = lidx;
        v[1] = binarysearch(nums,target,false)-1;//for right
        return v;
    }
};
