class MinStack {

    stack<int> s1,s2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || s2.top()>=val){
            s2.push(val);
        }
    }
    
    void pop() {
        if(s1.top()==s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        int ans= s1.top();
        return ans;
    }
    
    int getMin() {
        int ans= s2.top();
        return ans;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */