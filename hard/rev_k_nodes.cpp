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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head -> next == NULL || k == 1)
            return head;
        vector<ListNode*> v;
        
        for(ListNode* tmp = head; tmp != NULL; tmp = tmp -> next){
            v.push_back(tmp);
        }
        
        for(int i = 0; i < v.size()/k; i++)
            for(int j = 0; j < k/2; j++){
                //cout<<"ListNodes:    "<< v[(i*k)+j]-> val <<"  -  "<<v[(i*k)+k - j -1] -> val<<endl;
                //cout<<"Index Values: "<< (i*k)+j <<"  -  "<< (i*k)+k - j -1 <<endl;
                ListNode* tmp = v[(i*k)+j];
                v[(i*k)+j] = v[(i*k)+k - (j) -1];
                v[(i*k)+k - j -1] = tmp;
            }
        
        for(int i = 0; i < v.size(); i++){
                if(i == v.size()-1)
                    v[i] -> next = NULL;
                else
                    v[i] -> next = v[i+1];
        }
        
        return v[0];
        
    }
};