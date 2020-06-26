class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode *prev = new ListNode;
        ListNode *curr = prev;
        
        while(l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            sum = val1 + val2 + carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if(carry)
            curr->next = new ListNode(carry);
        
        curr = prev->next;
        delete prev;
        
        return curr;
    }
};
