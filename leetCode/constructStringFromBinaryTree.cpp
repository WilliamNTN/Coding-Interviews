//You need to construct a string consists of parenthesis and integers from a binary tree
//with the preorder traversing way.

//The null node needs to be represented by empty parenthesis pair "()". And you need to omit all
//the empty parenthesis pairs that don't affect the one-to-one mapping
//relationship between the string and the original binary tree.


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
    string buildStr(TreeNode* node){
        if(node == NULL) return "";
        string ans  = "";
        ans += to_string(node->val);
        
        if(node->right || node->left){
            ans += '(' + buildStr(node->left) + ')';
        }
        
        if(node->right){
            ans += '(' + buildStr(node->right) + ')';
        }
        
        return ans;
    }
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        char aux[33];
        string ans = "";
        ans += to_string(t->val);
        
        if(t->right || t->left)
         ans += '(' + buildStr(t->left) + ')';
        if(t->right)
            ans += '(' + buildStr(t->right) + ')';
   
        return ans;
    }
    
};