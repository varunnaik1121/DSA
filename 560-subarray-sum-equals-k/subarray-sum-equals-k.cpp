class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int target=sum-k;
            if(mpp.find(target)!=mpp.end()){
                ans+=mpp[target];
            }
            if(sum==k){
                ans++;
            }
            mpp[sum]++;
            

        }
        return ans;
    }
};