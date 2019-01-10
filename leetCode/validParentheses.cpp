
//Given a string containing just the characters
//'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//An input string is valid if:
//    Open brackets must be closed by the same type of brackets.
//   Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.


class Solution {
public:
    
    bool checkType(char open, char close){
        if(open == '(' && close == ')') return true;
        if(open == '{' && close == '}') return true;
        if(open == '[' && close == ']') return true;   
        return false;
    }
    
    bool isOpen(char c){
        return (c=='(' || c == '{' || c == '[');
    }
    
    bool isValid(string s) {
       stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if(isOpen(s[i])){
                st.push(s[i]);
            }
            else{
                if(st.size() == 0) return false;
                char open = st.top(); st.pop();
                if(!checkType(open,s[i])) return false;
            }
        }
        if(st.size()) return false;
        return true;
    }
    
};