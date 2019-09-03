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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp;
        ListNode* gnu;
        tmp = head;
        int listSize = 0;
        int counter = 0;
        
        while(tmp != NULL){
            listSize++;
            tmp = tmp -> next;
        }
        
        if(n > listSize)
            return head;
        if(n == listSize){
            head = head -> next;
            return head;
        }
        
        tmp = head;
        
        for(int i = 1; i <= listSize; i++){
            if((i + n) == listSize){
                gnu = tmp;
                gnu = gnu-> next;
                tmp -> next = gnu ->next;
            }
            if(tmp -> next == NULL)
                break;
            tmp = tmp -> next;
        }
        
        return head;
    }
};