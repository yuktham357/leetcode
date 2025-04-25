/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       unordered_set<ListNode*>see;
       while(head){
        if(see.find(head)!=see.end()){
            return head;
        }
        see.insert(head);
        head=head->next;
       }
       return nullptr;
    }
};