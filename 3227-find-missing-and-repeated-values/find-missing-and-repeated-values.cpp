class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp;
        int a,b;
        for(auto it:grid){
            for(int num:it){
                mpp[num]++;
            }
        }
       int n=grid.size();
       for(int i=1;i<=n*n;i++){
        if(mpp[i]>1){
            a=i;
        }
        else if(mpp[i]==0){
            b=i;
        }
       }
       return {a,b};
    }
};