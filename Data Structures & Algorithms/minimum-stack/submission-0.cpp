class MinStack {
public:
    
    stack<int> stk, minstk;
    
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        int mini = min(val, minstk.size() ? minstk.top(): val);
        minstk.push(mini);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
       return minstk.top();
    }
};
