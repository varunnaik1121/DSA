class Solution {
public:
    string helper(string filename){
        int i=0;
        int n=filename.size();
        string ans="";
        //(.) (..) (...)
        bool isAllAreDots=true;
        for(int i=0;i<n;i++){
            if(filename[i]!='.'){
                isAllAreDots=false;
                break;
            }else{
                ans+=filename[i];
            }
        }
        if(isAllAreDots){
            if(ans.size()==2) return "parent";
            else if(ans.size()==1) return "current";
            else return "filename";
            
        }else{
            return "filename";
        }
        return "";
    }
    string simplifyPath(string path) {
       stack<string> st;
       int i=0;
       int n=path.size();
       if(path=="") return "";
       string ans="";
       while(i<n){
        //this is the firts / that we have encountered so add it in the stack and find the next folder or the filename
            if(path[i]=='/'){
                if(i==n-1 && !st.empty()){
                    continue;
                }
                if((!st.empty() && st.top()!="/") || st.empty()){
                    st.push("/");
                }
                i++;
            }
            string filename=""; 
            while(i<n && path[i]!='/'){
                filename+=path[i++];
            }
            string status=helper(filename);
            if(filename.size()==0){
                continue;
            }
            else if(status=="parent"){
                 int toBeRemoved=2;
                while(!st.empty() && toBeRemoved>0){
                    st.pop();
                    toBeRemoved--;
                }
            }else if(status=="filename"){
                st.push(filename);
            }
           
       }
      
       while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
       }
       if(ans.size()>1 && ans.back()=='/'){
        ans.pop_back();
       }
       if(ans.size()==0 && path.size()>0) ans="/";
       return ans;
       
    }
};