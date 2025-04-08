class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto num:nums){
            mpp[num]++;
        }
        int ans=0;
        for(int i=0;i<n;i+=3){
            int j=i;
            if(mpp.size()==n-i) return ans;
            ans++;
            for(;j<min(n,i+3);j++){
                if(mpp.size()==n-j) return ans;
                mpp[nums[j]]--;
                if(mpp[nums[j]]==0) mpp.erase(nums[j]);
            }
        }
        return ans;
    }
};