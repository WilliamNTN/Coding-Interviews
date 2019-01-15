//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
    
    ListNode *append(ListNode* head, int val){
        ListNode* n = new ListNode(val);
        
        if(head == NULL){
            head = n;
            return head;
        }
        ListNode *node = head;
        while(node->next != NULL)
            node = node->next;
        node->next = n;
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        vector<ListNode*> heads;
        for(int i = 0; i < lists.size(); i++){
            ListNode *n = lists[i];
            heads.push_back(n);
        }
        
        
        ListNode* result = NULL;
        
        while(1){
            int min = 0;
            for(int i = 1; i < lists.size(); i++){
                if(heads[i] != NULL){
                    if(heads[min] == NULL || heads[i]->val < heads[min]->val)
                        min = i;
                }
            }
            if(heads[min] == NULL) break;
            result = append(result,heads[min]->val);
            heads[min] = heads[min]->next;
        }
        
        return result;
    }
};