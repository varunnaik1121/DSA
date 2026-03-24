class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int evenPlace=0;
        int oddPlace=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[evenPlace]=nums[i];
                evenPlace+=2;
            }else{
                ans[oddPlace]=nums[i];
                oddPlace+=2;
            }
        }
        return ans;
    }
};