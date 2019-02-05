/*
Given a string, find the length of the longest substring
without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        map<char,int> hash;
        int diffCount = 1;
        hash[s[0]]++;
        int ans = 0;
        int pt1 = 0;
        int pt2 = 0;
        
        while(pt2 < s.size()){
            
            while(pt2 < s.size() && pt2 - pt1 + 1 == diffCount){
                ans = max(ans,pt2-pt1+1);
                pt2++;
                if(hash[s[pt2]] == 0){
                    diffCount++;
                }
                hash[s[pt2]]++;
            }
            
            while(pt2 - pt1 + 1 > diffCount){
                hash[s[pt1]]--;
                if(hash[s[pt1]] == 0) diffCount--;
                pt1++;
            }
        }
        
        return ans;
    }
};