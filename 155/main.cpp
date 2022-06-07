class MinStack
{
public:
    stack<int> s, sm;
    MinStack()
    {
        s = stack<int>();
        sm = stack<int>();
    }

    void push(int val)
    {
        s.push(val);
        sm.push(sm.empty() ? val : min(val, sm.top()));
    }

    void pop()
    {
        s.pop();
        sm.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return sm.top();
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