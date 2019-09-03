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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool allNull = true;
        if(lists.size() == 0){
            return nullptr;
        }
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL)
                allNull = false;
        }
        if(lists.size() == 1 || allNull){
            return lists[0];
        }
        vector<int> listVals;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i] != NULL){
                listVals.push_back(lists[i] -> val);
                lists[i] = lists[i] -> next;
            }
        }
        sort(listVals.begin(), listVals.end());
        ListNode* gnu = new ListNode(listVals[0]);
        ListNode* tail = gnu;
        for(int i = 1; i < listVals.size(); i++){
            ListNode* tmp = new ListNode(listVals[i]);
            tail -> next = tmp;
            tail = tail -> next;
        }
        
        return gnu;
    }
};