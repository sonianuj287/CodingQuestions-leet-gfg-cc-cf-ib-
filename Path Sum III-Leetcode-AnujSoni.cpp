class Solution {
public:
    int pathcount;
    
    void getSum(TreeNode* root, int sum){
        if(!root)
            return;
        if(sum == root->val)
            pathcount++;
        getSum(root->left,sum-root->val);
        getSum(root->right,sum-root->val);
    }
    
    int pathSum(TreeNode* root, int sum) { 
        if(root){
            getSum(root,sum);
            pathSum(root->left,sum);
            pathSum(root->right,sum);
        }
        return pathcount;
    }
};
