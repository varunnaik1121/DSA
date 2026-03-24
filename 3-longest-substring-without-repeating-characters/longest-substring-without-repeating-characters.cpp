class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int L=0,R=0;
        int n=s.size();
        int sz=0;
        int ans=0;
        while(L<=R && R<n){
            mpp[s[R]]++;
           
            while(R<n && mpp[s[R]]>1){
                mpp[s[L]]--;
                L++;
            }
            ans=max(ans,R-L+1);
            R++;
        }
        return ans;
    }
};