class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int L=0;
        int L1=0;
        string ans="";
        while(L<word1.size() && L1<word2.size()){
            ans+=word1[L++];
            ans+=word2[L1++];
        }
        while(L<word1.size()){
            ans+=word1[L++];
        }
        while(L1<word2.size()){
            ans+=word2[L1++];
        }
        return ans;
    }
};