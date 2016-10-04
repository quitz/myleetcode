class Solution {
public:
    bool hasCycle(ListNode *head){
        ListNode *fast, *slow;
        if(head==NULL || head->next==NULL)
            return false;
        fast = head;
        slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};