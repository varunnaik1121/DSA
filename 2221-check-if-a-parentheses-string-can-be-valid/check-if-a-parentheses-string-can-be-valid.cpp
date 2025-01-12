class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0) return false;
        stack<int> locked_st;
        stack<int> unlocked_st;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    locked_st.push(i);
                }else{
                    if(locked_st.size()>0 && s[locked_st.top()]=='('){
                        locked_st.pop();
                    }else{
                        if(unlocked_st.size()>0){
                            unlocked_st.pop();
                        }else{
                            return false;
                        }
                    }
                }
            }else{
                unlocked_st.push(i);
            }
        }
        
        while(locked_st.size()>0 && unlocked_st.size()>0){
            if(locked_st.top()<unlocked_st.top()){
                locked_st.pop();unlocked_st.pop();
            }else{
                return false;
            }
        }
        // if(locked_st.size()>0) return false;
        if(unlocked_st.size()%2==0 && locked_st.size()==0) return true;
        return false;
    }
};