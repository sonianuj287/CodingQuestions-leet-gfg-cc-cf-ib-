class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        while(left<right){
            int mid = left+(right-left) /2;
            if(isBadVersion(mid)) //may be bad version also true for less tha mid
                right = mid;
            else
                left = mid+1;
        }
        if(left == right && isBadVersion(left))
            return left;
        return -1;
    }
};
