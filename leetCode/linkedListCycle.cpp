/*
Check if there is a cycle in a linkedList
*/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == head) return true;
      
        ListNode *fast = head;
        ListNode *slow = head;
        
        fast = fast->next;
        if(fast) fast = fast->next;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow)break;
        }
        
        return fast == slow;
      
        
    }
};