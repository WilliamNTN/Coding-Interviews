/*
Merge two sorted linked lists and return it as a new list
The new list should be made by splicing together the nodes of the first two lists.
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
    
    ListNode* append(ListNode *l, int val){
        
        ListNode *newNode = new ListNode(val);
        
        if(l == NULL){
            l = newNode;
            return l;
        }
        ListNode*n = l;
        
        while(n->next != NULL) n = n->next;
        
        n->next = newNode;
        return l;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
       
        ListNode *one = l1;
        ListNode *two = l2;
        
        ListNode *result = NULL;
        
        while(one != NULL && two != NULL){
            if(one->val <= two->val){
                result = append(result,one->val);
                one = one->next;
            }
            else{
                result = append(result,two->val);
                two = two->next;
            }
        }
        
        while(one != NULL){
            result = append(result,one->val);
            one = one->next;
        }
        while(two != NULL){
            result = append(result,two->val);
            two = two->next;
        }
        
        return result;
        
    }
};