
//Given preorder and inorder traversal of a tree, construct the binary tree.

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
    
    int findIndex(vector<int> array, int start, int end, int value){
        
        for(int i = start; i<=end; i++)
            if(array[i] == value) return i;
        return -1;
    }
    TreeNode *buildTree(vector<int> preorder, vector<int> inorder, int preStart, int inStart, int inEnd){
        if(preStart >= preorder.size()) return NULL;
        if(inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = findIndex(inorder,inStart,inEnd,root->val);
        
        root->left = buildTree(preorder,inorder,preStart+1,inStart,inIndex-1);
        root->right = buildTree(preorder,inorder,preStart+(inIndex-inStart+1),inIndex+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     
        return buildTree(preorder,inorder,0,0,inorder.size()-1);
    }
};