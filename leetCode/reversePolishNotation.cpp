class Solution {
public:
    bool isOp(string c){
        return (c == "+" ||  c == "-" || c == "*" || c == "/");
    }
    
    int apply(int a, int b, string op){
        int r;
        if(op == "+") r = a+b;
        if(op == "-") r = a-b;
        if(op == "*") r = a*b;
        if(op == "/") r = a/b;
        
        return r;
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<int> q;
        for(int i = 0; i < tokens.size(); i++){
            if(isOp(tokens[i])){
                int b = q.top(); q.pop();
                int a = q.top(); q.pop();
                int r = apply(a,b,tokens[i]);
                q.push(r);
            }
            else{
                q.push(stoi(tokens[i]));
            }
        }
        return q.top();
        
    }
};