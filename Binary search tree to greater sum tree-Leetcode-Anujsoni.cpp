/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& v){
        if(root){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    void inorderfill(TreeNode* root,vector<int>& v,int& i){
        if(root){
            inorderfill(root->left,v,i);
            root->val = v[i++];
            inorderfill(root->right,v,i);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> v;
        inorder(root,v);
        for(int i=v.size()-2;i>=0;i--)
            v[i] = v[i]+v[i+1];
        int i=0;
        inorderfill(root,v,i);
        return root;
    }
};
