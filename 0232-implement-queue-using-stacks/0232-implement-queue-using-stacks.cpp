class MyQueue {
private:
    stack<int>a,b;
    void change(stack<int>&x,stack<int>&y){
        while(!x.empty()){
            int tmp=x.top();
            x.pop();
            y.push(tmp);
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        change(a,b);
        int tmp=b.top();
        b.pop();
        change(b,a);
        return tmp;
    }
    
    int peek() {
        change(a,b);
        int tmp=b.top();
        change(b,a);
        return tmp;
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */