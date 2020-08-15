TreeNode* solve(int l,int h,vector<int>& pre,int il,int ih,unordered_map<int,int> &index){
    if(l>h)
        return NULL;
    TreeNode* root=new TreeNode(pre[l]);
    int i=index[pre[l]];
    int d=i-il;
    root->left=solve(l+1,l+d,pre,il,i-1,index);
    root->right=solve(l+d+1,h,pre,i+1,ih,index);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    if(pre.empty()||in.empty()||in.size()!=pre.size())
        return NULL;
    unordered_map<int,int> index;
    for(int i=0;i<pre.size();i++)
        index[in[i]]=i;
    return solve(0,in.size()-1,pre,0,in.size()-1,index);
}
