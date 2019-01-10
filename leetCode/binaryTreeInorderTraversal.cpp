//Given a binary tree, return the inorder traversal of its nodes' values.
//Follow up: Recursive solution is trivial, could you do it iteratively?


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
    
    vector<int> inOrder(TreeNode *node, vector<int> ans){
        if(node == NULL) return ans;
        
        ans = inOrder(node->left,ans);
        ans.push_back(node->val);
        ans = inOrder(node->right,ans);
        
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
       // Recursive
        //Time: O(n), Space: O(depth)
        // vector<int> ans;
        // return inOrder(root,ans);
        
        
        //Iterative
        //TIme: O(n), Space: O(depth)
        vector<int> ans;
        stack<TreeNode* >st;
        TreeNode *cur = root;
    
        while(cur || st.size()){  
            while(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        
        return ans;
    }
};