//Given a Binary Search Tree (BST), convert it to a Greate
//Tree such that every key of the original BST is changed to the
//original key plus sum of all keys greater than the original key in BST.


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
    
    int inOrder(TreeNode* node, int sum){
        if(node == NULL) return sum;
        
        int rightValue = inOrder(node->right,sum);
        node->val += rightValue;
        return inOrder(node->left,node->val);
     
    }
    
    TreeNode* convertBST(TreeNode* root) {
        
        inOrder(root,0);
        
        return root;
    }
};