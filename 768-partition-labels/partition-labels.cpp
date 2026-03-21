class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]=i;
        }
        vector<int> ans;
        int start=0;
        int n=s.size();
        while(start<n){
            int j=start;
            int end=mpp[s[start]];
            while(j<end){
                end=max(end,mpp[s[j]]);
                j++;
            }
            ans.push_back(j-start+1);
            start=j+1;
        }
        return ans;
    }
};