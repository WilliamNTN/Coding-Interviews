/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some
starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.
*/

class Solution {
public:
    
    int maxPath(TreeNode* root, int& maxSoFar){
        if(root == NULL) return 0;
        int l = maxPath(root->left,maxSoFar);
        int r = maxPath(root->right,maxSoFar);
        
        maxSoFar = max(maxSoFar,root->val+l+r);
        maxSoFar = max(maxSoFar,root->val+l);
        maxSoFar = max(maxSoFar,root->val+r);
        
        return max(root->val+l,max(root->val+r,root->val));
        
        
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = root->val;
        maxPath(root,ans);
        return ans;
    }
};