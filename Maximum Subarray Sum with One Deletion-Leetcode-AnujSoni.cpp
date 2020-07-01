class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int answer = arr[0];
        int suf_no_del = arr[0];
        int suf_del = 0;
        for(int i=1;i<n;i++){
            suf_del = max(suf_del+arr[i],suf_no_del);
            suf_no_del = max(suf_no_del+arr[i],arr[i]);
            answer = max({answer,suf_del,suf_no_del});
        }
        return answer;
    }
};
