TreeNode* rec(ListNode* A){
    if(!A)
        return NULL;
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root = NULL;
    if(slow)
        root = new TreeNode(slow->val);
    if(root){
        ListNode* t = slow->next;
        if(prev){
            prev->next = NULL;
            root->left = rec(A);
        }
        if(t)
            root->right = rec(t);
    }
    return root;
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    TreeNode* root = rec(A);
    return root;
}
