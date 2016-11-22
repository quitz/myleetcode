class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(s1.size()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }

    // Get the front element.
    int peek(void) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int r = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return r;
        
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
private:
    stack<int> s1,s2;
    
};