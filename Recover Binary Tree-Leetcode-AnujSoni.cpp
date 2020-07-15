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
    TreeNode* elem1;
    TreeNode* elem2;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            if(prev != NULL && root->val < prev->val){
                if(elem1 == NULL)
                    elem1 = prev;
                elem2 = root;
            }
            prev = root;
            inorder(root->right);
        }
    }
    
    void recoverTree(TreeNode* root) {
        prev = NULL;
        inorder(root);
        int temp = elem1->val;
        elem1->val = elem2->val;
        elem2->val = temp;
    }
};
