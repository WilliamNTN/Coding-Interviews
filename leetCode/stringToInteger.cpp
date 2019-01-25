//Implement atoi which converts a string to an integer.
class Solution {
public:
    int myAtoi(string str) {
        int ptr = 0;
    
        int mult = 1;
        while(str[ptr] == ' ') ptr++;
        
        if(str[ptr] == '+' || str[ptr] == '-'){
            if(str[ptr] == '-') mult = -1;
            ptr++;
        }
        int num = 0;
        while(ptr < str.size() && isdigit(str[ptr])){
            int toAdd = str[ptr]-'0';
            if(((INT_MAX-toAdd)/10) < num) return mult == 1? INT_MAX : INT_MIN;
            num = num*10 + toAdd;
            ptr++;
        }
        
        return num*mult;
    }
};