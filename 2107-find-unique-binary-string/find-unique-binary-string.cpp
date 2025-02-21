class Solution {
    void backtrack(set<string> &st,int idx,int len,string &ans,string op){
        if(idx>=len){
            if(st.find(op)==st.end()){
                ans=op;
                return ;
            }
            return;
            
        }
        if(ans.size()>0) return;

        backtrack(st,idx+1,len,ans,op+"0");
        backtrack(st,idx+1,len,ans,op+"1");
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(),nums.end());
        int len=nums[0].size();
        string ans="";
        backtrack(st,0,len,ans,"");
        return ans;
    }
};