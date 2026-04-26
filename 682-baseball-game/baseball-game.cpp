class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum=0;
        int n=operations.size();
        for(int i=0;i<n;i++){
            if(operations[i]=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second);
                st.push(first);
                st.push(first+second);
                sum+=st.top();
            }else if(operations[i]=="C"){
                sum-=st.top();
                st.pop();
            }else if(operations[i]=="D"){
                st.push(st.top()*2);
                sum+=st.top();
            }else{
                st.push(stoi(operations[i]));
                sum+=st.top();
            }
        }
        return sum;
    }
};