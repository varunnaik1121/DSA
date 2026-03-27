class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26,0);
        int i=0,j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            mpp[s[j]-'A']++;
            int maxi=0;
            for(int k=0;k<26;k++){
                maxi=max(maxi,mpp[k]);
            }
            if(((j-i+1) -maxi) > k){
                mpp[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};