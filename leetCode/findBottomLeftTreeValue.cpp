//Given a binary tree,
//find the leftmost value in the last row of the tree. 

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
    int bfs(TreeNode* root){
    
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,0));
        int actualLevel = 0;
        int actualValue = root->val;
        
        while(q.size()){
        pair<TreeNode*,int> result = q.front(); q.pop();
        TreeNode* r = result.first;
        int level = result.second;
            
        if(level > actualLevel){
            actualLevel = level;
            actualValue = r->val;
        }
            
        if(r->left)
            q.push(make_pair(r->left,level+1));
        if(r->right)
            q.push(make_pair(r->right,level+1));
        }
    return actualValue;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);    
    }
};