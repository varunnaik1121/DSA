class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        int freq[26]={0};
        for(auto ch:s){
            freq[ch-'a']++;
        }
        int oddCount=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) oddCount++;
        }
        return oddCount<=k;
    }
};