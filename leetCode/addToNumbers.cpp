//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    
    int getSize(ListNode *head){
        if(head == NULL) return 0;
        ListNode *n = head;
        int size = 0;
        
        while(n != NULL){
            size++;
            n = n->next; 
        }
        
        return size;
    }
    
    ListNode* appendToList(ListNode *head, int value){
        ListNode *newNode = new ListNode(value);
        
        if(head == NULL){
            head = newNode;
            return head;
        }
        ListNode *n = head;
        while(n->next != NULL) n = n->next;
        n->next = newNode;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *small = getSize(l1) >= getSize(l2)? l2:l1;
        ListNode *big = getSize(l1) >= getSize(l2)? l1:l2;
        
        ListNode* solution = NULL;
        int carry = 0;
        while(small != NULL){
            int sum = small->val + big->val + carry;
            if(sum >= 10) carry = 1;
            else carry = 0;
            sum = sum%10;
            solution = appendToList(solution,sum);
            
            small = small->next;
            big = big->next;
        }
        
        while(big != NULL){
            int sum = big->val + carry;
            if(sum >= 10) carry = 1;
            else carry = 0;
            
            sum = sum%10;
            
            solution = appendToList(solution,sum);
            big = big->next;
        }
        
        if(carry){
            solution = appendToList(solution,carry);
        }
        
        return solution;
        
    }
};