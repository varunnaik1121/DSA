class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        int count=0;
        int i=0,j=0;
        int ans=0;
        int n=s.size();
        while(j<n && i<n){
            mpp[s[j]]++;
            if(mpp[s[j]]==1){
                count++;
            }
            if(count==3){
                ans+=n-j;
            }
            while(count>=3){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    count--;
                }
                if(count==3){
                    ans+=n-j;
                }
                i++;
            }
            j++;
           
        }
        return ans;
    }
};