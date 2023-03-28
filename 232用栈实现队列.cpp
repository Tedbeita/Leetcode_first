class MyQueue {
public:
    stack<int> stackin;
    stack<int> stackout;


    MyQueue() {
    
    }
    
    void push(int x) {
        stackin.push(x);
    }
    
    int pop() {
        if(stackout.empty())
        {
            while(!stackin.empty())
            {
                stackout.push(stackin.top());
                stackin.pop();
            }
        }
        int result = stackout.top();
        stackout.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        stackout.push(result);
        return result;
    }
    
    bool empty() {
        if(!stackout.empty() || !stackin.empty())
        {
            return false;
        }
        return true;
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
