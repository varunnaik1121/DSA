class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string dg="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                dg+=s[i];
            }else{
                if(s[i]=='['){
                    if(dg!=""){
                        st.push(dg);
                        dg="";
                    }
                    st.push(string(1,s[i]));
                }else if(s[i]==']'){
                    string temp="";
                    while(!st.empty() && st.top()!="["){
                        temp=st.top()+temp;
                        st.pop();
                    }
                    st.pop();
                    int times=stoi(st.top());
                    st.pop();
                    string ans="";
                    while(times--){
                        ans+=temp;
                    }
                    st.push(ans);
                }else{
                    st.push(string(1,s[i]));
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};