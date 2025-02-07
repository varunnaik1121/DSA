class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        vector<int> ans;
        for(auto query:queries){
            int ball=query[0];
            int color=query[1];
            if(mpp1.find(ball)!=mpp1.end()){
                int prevColor=mpp1[ball];
                mpp1[ball]=color;
                mpp2[prevColor]--;
                if(mpp2[prevColor]==0){
                    mpp2.erase(prevColor);
                }
                mpp2[color]++;

            }else{
                mpp1[ball]=color;
                mpp2[color]++;
            }
            ans.push_back(mpp2.size());
        }
        return ans;
        

    }
};