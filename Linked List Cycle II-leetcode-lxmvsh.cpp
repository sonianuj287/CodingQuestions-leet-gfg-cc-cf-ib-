class Solution {
public:
    ListNode *LoopDetect(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
    if(head==NULL || head->next==NULL)
            return NULL;
    ListNode  *Loopdetect=LoopDetect(head);
    if(Loopdetect==NULL)
        return NULL;
    ListNode *start=head;
    while(Loopdetect!=start){
        start=start->next;
        Loopdetect=Loopdetect->next;
    }    
    return start;
    }
    };
