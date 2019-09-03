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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* sol;
        ListNode* solHead;
        if(l1 == NULL || l2 == NULL){
            if (l1 == NULL)
                return l2;
            if (l2 == NULL)
                return l1;
        }
        
        if(l1->val < l2->val){
            sol = l1;
            solHead = sol; 
            l1 = l1-> next;  
        }
        else{
            sol = l2;
            solHead = sol; 
            l2 = l2-> next;
        }
        
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL && l2 != NULL){
                sol -> next = l2;
                sol = sol -> next;
                l2 = l2 -> next;
                continue;
            }
                    
            if (l2 == NULL && l1 != NULL){
                sol -> next = l1;
                sol = sol -> next;
                l1 = l1 -> next;
                continue;
            }
            if(l1->val > l2->val){
                sol->next = l2;
                sol = sol -> next;
                l2 = l2 -> next;
                continue;
            }
            else{
                sol->next = l1;
                sol = sol -> next;
                l1 = l1 -> next;
                continue;
            }
        }      
        
        return solHead;

    }
};