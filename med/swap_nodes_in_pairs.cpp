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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr || head -> next == NULL)
            return head;
        ListNode* t0 = head;
        ListNode* t1 = head -> next;
        if(t1 -> next == NULL){
            t1 -> next = t0;
            t0 -> next = NULL;
            head = t1;
            return head;
        }
        ListNode* t2 = t0;
        head = t1;
        t0 -> next = t1 -> next;
        t1 -> next = t0;
        t1 = t0 -> next;
        t2 = t1 -> next;
        while((t0 -> next) != NULL){
            if(t2 == NULL){
                return head;
            }
            t0 -> next = t2;
            t1 -> next = t2 -> next;
            t2 -> next = t1;
            t0 = t1;
            t1 = t1 -> next;
            if(t1  == NULL)
                t2 = NULL;
            else
                t2 = t1 -> next;
        }
        
        return head;
    }
};