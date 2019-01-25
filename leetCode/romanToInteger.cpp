class Solution {
public:
    
    int convert(char c){
        switch(c){
            /*
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000*/
            
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }
    
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.size();i++){
            if((i+1) < s.size() && convert(s[i+1]) > convert(s[i])){
                sum+= convert(s[i+1])-convert(s[i]);
                i++;
            }
            else sum+= convert(s[i]);
        }
        
        return sum;
    }
};