/*
Given an array of strings, group anagrams together.
*/

class Solution {
public:
    
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        vector<vector<string>> ans;
        int n = strs.size(); if(n==0) return ans;
    
        map<string,vector<string>> mp;
        
        for(int i = 0; i < n; i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(strs[i]);
        }
        
        map<string,vector<string>>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;  
    }
};