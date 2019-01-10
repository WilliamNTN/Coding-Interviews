//Validate Binary Search Tree. No duplicates

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
    
    bool isValid(TreeNode *root, TreeNode *min, TreeNode* max){
       if(root == NULL) return true;
        
        if(min && root->val <= min->val || max && root->val >= max->val) return false;
        
        return isValid(root->left,min,root) & isValid(root->right,root,max);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        return isValid(root,NULL,NULL);
    }
};