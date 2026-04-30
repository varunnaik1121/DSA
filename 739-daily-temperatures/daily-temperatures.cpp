class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> warmDaysIdx(n,0);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            int currDayTemp=temperatures[i];
            if(st.empty()){
                st.push({currDayTemp,i});
                warmDaysIdx[i]=i-i;
            }else{
                while(!st.empty() && currDayTemp>=st.top().first){
                    st.pop();
                }
                if(st.empty()){
                    st.push({currDayTemp,i});
                    warmDaysIdx[i]=i-i;
                }else{
                    warmDaysIdx[i]=st.top().second-i;
                    st.push({currDayTemp,i});
                }
            }
        }
        return warmDaysIdx;
        
    }
};