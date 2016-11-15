class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mins;
    MinStack() {
    }
    
    void push(int x) {
        if(mins.empty() || x<= mins.top() )
            mins.push(x);
        s.push(x);
    }
    
    void pop() {
        if(s.empty())
            return;
        if(s.top() == mins.top())
            mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
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