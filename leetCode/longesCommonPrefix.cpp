//Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ptr = 0;
        bool done = 0;
        string ans = "";
        if(strs.size() == 0)return ans;
        while(!done){
            if(ptr >= strs[0].size()) return ans;
            char c = strs[0][ptr];
            
            for(int i = 1; i < strs.size(); i++)
                if(ptr >= strs[i].size() || strs[i][ptr] != c) done = 1;
            
            if(!done) ans += c;
            ptr++;
        }
        return ans;
    }
};