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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0,b=0;
        ListNode* p1=headA;
        ListNode* p2=headB;
        while(p1){
            a++;
           p1=p1->next;
        }
         while(p2){
            b++;
            p2=p2->next;
        }
        int t=abs(a-b);
        if(a>b){
            while(t){
                headA=headA->next;
                t--;
            }
        }
        else{
            while(t){
                headB=headB->next;
                t--;
            }
        }
        while(headA && headB){
            if(headA == headB){
                return headB;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};