/*
Write a program to find the node at which the intersection of two singly linked lists begins.
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
    
    int size(ListNode *head){
        if(head == NULL) return 0;
        
        ListNode *n = head;
        int ans = 0;
        while(n != NULL){
            ans++;
            n = n->next;
        }
        
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int nA = size(headA);
        int nB = size(headB);
        if(!nA || !nB) return NULL;
        ListNode *greater = nA >= nB ? headA : headB;
        ListNode *smaller = nA >= nB ? headB : headA;
        
        int move = abs(nA - nB);
        
        while(move){
            greater = greater->next;
            move--;
        }
        
        while(greater != NULL && greater != smaller){
            greater = greater->next;
            smaller = smaller->next;
        }
        
        return greater;
    }
};