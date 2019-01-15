//Given a singly linked list, determine if it is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode *prev = NULL, *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;

            ListNode *nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;

        }

        if(fast != NULL) slow = slow->next;

        ListNode *h1 = prev;
        ListNode *h2 = slow;

        while(h2 != NULL){
            if(h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;

    }
};