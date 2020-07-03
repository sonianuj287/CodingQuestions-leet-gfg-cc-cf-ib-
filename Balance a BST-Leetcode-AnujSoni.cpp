class Solution {
public:
    void inorder(TreeNode* root,vector<TreeNode*>& v){
        if(root){
            inorder(root->left,v);
            v.push_back(root);
            inorder(root->right,v);
        }
    }
    TreeNode* constructBST(int low, int high, vector<TreeNode*>& arr) {
        if (low > high)
            return NULL;
            
        int mid = (low + high) / 2;
        auto root = arr[mid];
        
        root->left = constructBST(low, mid - 1, arr);
        root->right = constructBST(mid + 1, high, arr);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root,v);
        return constructBST(0,v.size()-1,v);
    }
};
