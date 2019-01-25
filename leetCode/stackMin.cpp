/*
Design a stack where it is possible to get minValue in constant time
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int x) {
        pair<int,int> add;
        add.first = x;
        
        if(st.size() == 0) add.second = x;
        else add.second = x < getMin() ? x : getMin();
        
        st.push(add);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */