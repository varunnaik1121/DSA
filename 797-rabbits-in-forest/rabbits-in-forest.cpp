class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mpp;
        for(auto &x:answers){
            mpp[x]++;
        }
        int ans=0;
        for(auto &it:mpp){
            int x=it.first;
            int count=it.second;
            int grpSize=(x+1);
            int groups=ceil((double)count/grpSize);
            ans+=groups*grpSize;

        }
        return ans;
        
    }
};