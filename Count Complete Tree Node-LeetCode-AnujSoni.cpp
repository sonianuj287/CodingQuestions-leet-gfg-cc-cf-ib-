class Solution {
public:
    void count(TreeNode* root,int &total){
        if(!root)
            return;
        if(root)
           total++; 
        count(root->left,total);
        count(root->right,total);
    }
    
    int countNodes(TreeNode* root) {
        int total = 0;
        count(root,total);
        return total;
    }
};
