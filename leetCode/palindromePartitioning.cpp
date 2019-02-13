/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.
*/

class Solution {
public:
    
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;r--;
        }
        return true;
    }
    
    void bt(int index, string s, vector<string>& path, vector<vector<string>>& ret){
        if(index == s.size()){
            ret.push_back(path);
            return;
        }
        
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                bt(i+1,s,path,ret);
                path.pop_back();
            }
        }
        
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path; 
        if(s.size() == 0) return ans;
        bt(0,s,path,ans);
        return ans;
    }
};