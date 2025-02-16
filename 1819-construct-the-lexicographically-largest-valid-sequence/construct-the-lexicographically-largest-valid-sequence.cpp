class Solution {
    private:
        bool backtrack(vector<int> &ans,int n,set<int> &used,int idx){
            if(idx>=ans.size()) return true;
            for(int num=n;num>=1;num--){
                if(used.find(num)!=used.end()){
                    continue;
                }
               if(num>1 && (num+idx>=ans.size() || ans[num+idx])) continue;
               used.insert(num);
               ans[idx]=num;
               if(num>1){
                ans[idx+num]=num;
               }
               int j=idx+1;
               while(j<ans.size() && ans[j]){
                j++;
               }
               if(backtrack(ans,n,used,j)){
                return true;
               }
               used.erase(num);
               ans[idx]=0;
               if(num>1){
                ans[idx+num]=0;
               }

            }
            return false;
        }
public:
    vector<int> constructDistancedSequence(int n) {
        set<int> st;
        
        vector<int> ans(n*2-1,0);
        backtrack(ans,n,st,0);
        return ans;
    }
};