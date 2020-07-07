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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode* t = lists[i];
            while(t){
                pq.push(t->val);
                t = t->next;
            }
        }
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(!pq.empty()){
            int i = pq.top(); pq.pop();
            ListNode* n = new ListNode(i);
            temp->next = n;
            temp = temp->next;                
        }
        return head->next;
    }
};
