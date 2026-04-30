class StockSpanner {
    private:
        stack<pair<int,int>> st;
        int sz=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,sz++});  
            return 1;
        }else{
            while(!st.empty() && price>=st.top().first){
                st.pop();
            }
            if(st.empty()){
                st.push({price,sz++});
                return sz;
            }else{
                
                int ans=sz-st.top().second;
                st.push({price,sz++});
                return ans;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */