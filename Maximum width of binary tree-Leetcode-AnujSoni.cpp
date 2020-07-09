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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            int minval = INT_MAX, maxval = 0;
            while(s--){
                pair<TreeNode*,int> p = q.front();q.pop();
                TreeNode* temp = p.first;
                int t = p.second;
                if(temp->left){
                    q.push({temp->left,2*t});
                    minval = min(minval,2*t);
                    maxval = max(maxval,2*t);
                }
                if(temp->right){
                    q.push({temp->right,2*t-1});
                    minval = min(minval,2*t-1);
                    maxval = max(maxval,2*t-1);
                }
            }
            ans = max(ans,maxval-minval+1);
        }
        return ans;
    }
};
