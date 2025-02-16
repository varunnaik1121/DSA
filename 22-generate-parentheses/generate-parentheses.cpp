class Solution {
private:
    void backtrack(int open,int close,vector<string> &ans,string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        if(open==close){
            backtrack(open-1,close,ans,op+"(");
        }
        else if(open==0){
            backtrack(open,close-1,ans,op+")");
        }else{
            backtrack(open-1,close,ans,op+"(");
            backtrack(open,close-1,ans,op+")");
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        backtrack(n-1,n,ans,"(");
        return ans;
    }
};