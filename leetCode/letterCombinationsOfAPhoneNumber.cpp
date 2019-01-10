//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

class Solution {
public:
    vector<char> getChars(char digit){
        vector<char> ans;
        int start, end;
        
        switch(digit){
                
            case '2':
                start = 0;
                end = 3;
            break;
                
            case '3':
                start = 3;
                end = 6;
            break;
        
            case '4':
                start = 6;
                end = 9;
            break;
                
            case '5':
                start = 9;
                end = 12;
            break;
                
            case '6':
                start = 12;
                end = 15;
            break;
                
            case '7':
                start = 15;
                end = 19;
            break;
                
            case '8':
                start = 19;
                end = 22;
            break;
                
            case '9':
                start = 22;
                end = 26;
            break;
        }
        
        for(int i = start; i < end; i++){
            ans.push_back('a' + i);
        }
        
        return ans;
    }
    
    vector<string> buildStr(vector<vector<char>> pos, int posIndex, string soFar, vector<string> results){
        if(posIndex >= pos.size()){
            results.push_back(soFar);
            return results;
        }
        
        for(int i = 0; i<pos[posIndex].size(); i++){
            results = buildStr(pos,posIndex+1,soFar+pos[posIndex][i],results);
        }
        
        return results;
    }
    vector<string> generateAllCombinations(vector<vector<char>> pos){
        vector<string> ans;
        
        ans = buildStr(pos,0,"",ans);
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<vector<char>> pos;
        
        for(int i = 0; i < digits.size(); i++){
            pos.push_back(getChars(digits[i]));
        }
        vector<string> ans;
        if(pos.size() == 0) return ans;
        ans = generateAllCombinations(pos);
        
        return ans;
    }
};