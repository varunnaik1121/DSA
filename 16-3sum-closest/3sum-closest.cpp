class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int L=i+1;
            int R=n-1;
            while(L<R){
                int sum=nums[i]+nums[L]+nums[R];
                if(sum>target){
                    R--;
                }else{
                    L++;
                }
                if(abs(target-sum)<abs(ans-target)){
                    ans=sum;
                }
            }
        }
        return ans;
    }
};