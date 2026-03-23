class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0) return 0;
        int start=0,end=0;
        int n=nums.size();
        int ans=0;
        int prod=1;
        for(int end=0;end<n;end++){
            prod=prod*nums[end];
            while(start<=end && prod>=k){
                prod=prod/nums[start++];
            }
            
            ans+=(end-start)+1;
        }
        return ans;
    }
};