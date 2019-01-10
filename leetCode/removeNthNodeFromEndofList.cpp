

//Given a linked list, remove the n-th node from the end of list and return its head.

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
        
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode* fast = newHead, *slow = newHead;
        
        for(int i = 0; i < n; i++)
            fast = fast->next;
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return newHead->next;
    }
};