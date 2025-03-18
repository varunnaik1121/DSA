class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto num:mpp){
            if(num.second%2!=0) return false;
            ans+=num.second/2;
        }
        return ans==nums.size()/2;
    }
};