/*
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            vector<int> thisLevel;
            while(n--){
                TreeNode* node = q.front(); q.pop();
                thisLevel.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(thisLevel);
        }
        return ans;
    }
};