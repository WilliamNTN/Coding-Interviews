/*
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() == 0) return "";
        string ans = s.substr(0,1);
        int n = s.size();
        for(int i = 1; i < n; i++){
            int j = i-1;
            int k = i;
            while(j >= 0 && k < n && s[j] == s[k]){
                if(k-j+1 > ans.size()){
                    ans = s.substr(j,k-j+1);
                }
                j--; k++;
            }
            j = i-2; k = i;
            while(j >= 0 && k < n && s[j] == s[k]){
                if(k-j+1 > ans.size()){
                    ans = s.substr(j,k-j+1);

                }
                j--; k++;
            }            
        }
        
        return ans;
    }
};