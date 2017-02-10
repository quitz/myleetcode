/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    map<RandomListNode *, RandomListNode *> mp;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
            return nullptr;
        RandomListNode  *temp = head;
        if(mp[head] != nullptr)
            return mp[head];
        mp[head] = new RandomListNode(head->label);
        mp[head]->next = copyRandomList(head->next);
        mp[head]->random = copyRandomList(head->random);
        return mp[head];
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
            return nullptr;
        RandomListNode  *temp = head;
        map<RandomListNode *, RandomListNode *> mp;
        while(temp){
            mp[temp] = new RandomListNode(temp->label);
            temp = temp->next;
        }
    
        temp = head;
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};