class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        
        // Move the last (size - 1) elements to the back of the queue
        for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if (q.empty()) return -1; 
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
