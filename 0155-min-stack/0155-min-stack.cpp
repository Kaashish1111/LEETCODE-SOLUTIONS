class MinStack {
private:
    stack<long long> st;   // store either real value or encoded value
    long long mini;        // current minimum

public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int value) {
        long long v = value;
        if (st.empty()) {
            st.push(v);
            mini = v;
        } else {
            if (v > mini) {
                st.push(v);               // normal push
            } else {
                // store encoded value and update mini
                st.push(2 * v - mini);
                mini = v;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long x = st.top(); st.pop();
        if (x < mini) {
            // x is encoded value, restore previous minimum
            mini = 2 * mini - x;
        }
        if (st.empty()) {
            // reset mini so stack-empty state is consistent
            mini = LLONG_MAX;
        }
    }
    
    int top() {
        if (st.empty()) return -1;       // or throw
        long long x = st.top();
        if (x > mini) return (int)x;     // real value on top
        return (int)mini;                // encoded -> actual top is mini
    }
    
    int getMin() {
        if (st.empty()) return -1;       // or throw
        return (int)mini;
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