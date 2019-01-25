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
    TreeNode* append(TreeNode* tree, int val){
        TreeNode* newNode = new TreeNode(val);
        if(tree == NULL){
            tree = newNode;
            return tree;
        }
        
        if(val > tree->val) tree->right = append(tree->right,val);
        else tree->left = append(tree->left,val);
        return tree;
    }
    
    TreeNode* binaryAdd(TreeNode* tree,vector<int>& nums, int left, int right){
        if(right < left) return tree;
        int middle = left + (right-left)/2;
        tree = append(tree,nums[middle]);
        tree = binaryAdd(tree,nums,left,middle-1);
        tree = binaryAdd(tree,nums,middle+1,right);
        return tree;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          
        TreeNode* ans = NULL;
        ans = binaryAdd(ans,nums,0,nums.size()-1);
        return ans;
    }
};