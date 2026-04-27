class MinStack {
    private:
    stack<long long> st;
    long long minEle=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size()==0){
            st.push(val);
            minEle=val;
        }else{
            if(val>=minEle){
                st.push(val);
            }else{
                st.push((long long)val * 2 - minEle);
                minEle=val;
            }
        }
    }
    
    void pop() {
        if(st.size()==0) return;
        if(st.top()<minEle){
            long long temp=st.top();
            minEle=(minEle*2)-temp;
            st.pop();
        }else{
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<minEle){
            return minEle;
        }else{
            return st.top();
        }
    }
    
    int getMin() {
        return minEle;
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