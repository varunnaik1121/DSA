class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int temp=nums[0];
        ans=max(ans,temp);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                temp+=nums[i];
            }else{
                temp=nums[i];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};