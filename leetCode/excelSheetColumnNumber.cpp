//Given a column title as appear in an Excel sheet, return its corresponding column number.
class Solution {
public:
    
    int map(char c){
        return c - 'A' + 1;
    }
    int titleToNumber(string s) {
        
        int result = 0;
        for(int i = s.size()-1; i >=0; i--){
            result += map(s[i]) * pow(26,s.size()-1-i);
        }
        return result;
    }
};