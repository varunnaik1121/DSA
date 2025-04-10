class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> st;
        int n=A.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            st.insert(B[i]);
            ans[i]=(i+1)*2-st.size();
        }
        return ans;
    }
};