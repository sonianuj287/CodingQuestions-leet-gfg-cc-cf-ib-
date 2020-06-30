/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n == 0)
            return head;
        if(!head->next)
            return NULL;
        ListNode* temp = head;
        while(n--)
            temp = temp->next;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(!temp)
            return curr->next;
        
        
        while(temp){
            temp = temp->next;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
