/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int ans = INT_MIN;
    int inOrder(TreeNode* root, int k, int c){
        if(root == NULL) return c;
        c = inOrder(root->left,k,c);
        c++;
        if(k == c){
            ans = root->val;
        }    
        c = inOrder(root->right,k,c);
        return c;
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k,0);
        return ans;
    }
};