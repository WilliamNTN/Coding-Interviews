//A binary tree is univalued if every node in the tree has the same value.
//Return true if and only if the given tree is univalued.

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
    
    bool checkValue(TreeNode* node, int value){
        if(node == NULL) return true;
        if(node->val != value) return false;
        return checkValue(node->left,value) & checkValue(node->right,value);
    }
    bool isUnivalTree(TreeNode* root) {
       if(root == NULL) return false;
       int value = root->val;
       return checkValue(root->left,value) & checkValue(root->right,value);
    }
};