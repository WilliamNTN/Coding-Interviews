//Given two strings s and t , write a function to determine if t is an anagram of s.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        if(s.size() == 0) return true;
        
        map<int,int> inS;
        
        for(int i = 0; i < s.size(); i++)
            inS[s[i]]++;
        
        for(int i = 0; i < t.size(); i++)
            if(inS[t[i]]==0)
                return false;
            else
                inS[t[i]]--;
        
        return true;
    }
};