class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q.size()==1){
            q.pop();
            return;
            
        }
        while(q.size()!=1){
            t.push(q.front());
            q.pop();
        }
        q.pop();
        while(!t.empty()){
            q.push(t.front());
            t.pop();
        }
        //t.clear();
        return;
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
    queue<int> t;
};