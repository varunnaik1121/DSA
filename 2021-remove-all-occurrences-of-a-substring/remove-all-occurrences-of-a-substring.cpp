class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st1;
       
        int n=part.size();
        
        for(auto ch:s){
            st1.push(ch);
            int end=n-1;
             stack<char> st2;
             
            if(st1.top()==part.back()){
                while(end>=0 && st1.size()>0 && part[end]==st1.top() ){
                    st2.push(st1.top());
                    st1.pop();
                    end--;
                }
                if(end>=0){
                    while(!st2.empty()){
                        st1.push(st2.top());
                        st2.pop();
                    }
                }
            }
        }
        string ans="";
        while(!st1.empty()){
            ans+=st1.top();
            st1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};