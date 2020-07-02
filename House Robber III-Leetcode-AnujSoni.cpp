class Solution {
public:
    vector<int> rec(TreeNode* root){
        vector<int> v(2,0);
        if(!root)
            return v;
        vector<int> left = rec(root->left);
        vector<int> right = rec(root->right);
        v[0] = root->val + left[1] + right[1];
        v[1] = max(left[0],left[1])+max(right[0],right[1]);
        return v;
    }
    
    int rob(TreeNode* root) {
        vector<int> v = rec(root);
        return max(v[0],v[1]);
    }
};
