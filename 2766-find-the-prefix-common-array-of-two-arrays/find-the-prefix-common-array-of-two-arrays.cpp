class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> st;
        int n=A.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            st.insert(B[i]);
            int temp=0;
            for(int j=0;j<=i;j++){

                if(st.find(A[j])!=st.end()){
                    temp++;
                }
            }
            ans[i]=temp;
        }
        return ans;
    }
};