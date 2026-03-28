class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int start=0,end=0;
        unordered_map<int,int> mpp;
        while(end<nums.size()){
            mpp[nums[end]]++;
            while(end-start > k){
                mpp[nums[start]]--;
                start++;
            }
            if(mpp[nums[end]]>=2) return true;
            end++;
        }
        return false;
    }
};