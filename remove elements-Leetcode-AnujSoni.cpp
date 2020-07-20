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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        if(head->val == val){
            while(head){
                if(head->val != val)
                    break;
                head = head->next;
            }
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            if(temp->val == val){
                prev->next = temp->next;
                temp = prev;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
