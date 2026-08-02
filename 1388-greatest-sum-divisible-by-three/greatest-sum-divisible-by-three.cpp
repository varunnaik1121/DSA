class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> remain1;
        vector<int> remain2;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]%3==1){
                remain1.push_back(nums[i]);
            }
            if(nums[i]%3==2){
                remain2.push_back(nums[i]);
            }
        }
        if(sum%3==0) return sum;
        sort(remain1.begin(),remain1.end());
        sort(remain2.begin(),remain2.end());
        int ans=0;
        if(sum%3==1){
            int remove1=remain1.size()>0?remain1[0]:INT_MAX;
            int remove2=remain2.size()>1 ? remain2[0]+remain2[1]:INT_MAX;
            ans=max(ans,sum-min(remove1,remove2));
        }
        if(sum%3==2){
            int remove1=remain1.size()>1?remain1[0]+remain1[1]:INT_MAX;
            int remove2=remain2.size()>0 ? remain2[0]:INT_MAX;
            ans=max(ans,sum-min(remove1,remove2));
        }
        return ans;
    }
};