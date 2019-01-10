//Given a binary tree, return the zigzag level order traversal of its nodes
//values. (ie, from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        
        //Time O(n)  Space O(n)
        
//         queue<TreeNode*> q;
//         q.push(root);
//         bool fromRight = false;
//         while(q.size()){
//             int size = q.size();
//             TreeNode *cur;
//             stack<TreeNode*> st;
//             vector<int> thisLine;
            
//             while(size--){
//                 cur = q.front(); q.pop();
//                 st.push(cur);
//             }
            
//             while(st.size()){
//                 cur = st.top(); st.pop();
//                 thisLine.push_back(cur->val);
                
//                 if(cur->left && cur->right){
//                     if(fromRight){
//                         q.push(cur->right);
//                         q.push(cur->left);
//                     }
//                     else{
//                         q.push(cur->left);
//                         q.push(cur->right);
//                     }
//                 }
//                 else if(cur->left)
//                     q.push(cur->left);
                
//                 else if(cur->right)
//                     q.push(cur->right);
                
//             }
//             ans.push_back(thisLine);
//             fromRight = !fromRight;
//         }
        
        
        //Time: O(n), Space: O(n) (lower constant, no stack)
        
        queue<TreeNode*> q;
        q.push(root);
        bool fromRight = false;
        
        while(q.size()){
            int size = q.size();
            vector<int> thisLine(size,0);
            for(int i = 0; i<size; i++){
                TreeNode* cur = q.front(); q.pop();
                int thisIndex = fromRight? size-1-i : i;
                thisLine[thisIndex] = cur->val;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(thisLine);
            fromRight = !fromRight;
        }
        return ans;
    }
};