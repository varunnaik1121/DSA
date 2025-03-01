class Solution {
    static bool comp(int &a,int &b){
      if(b==0){
        return true;
      }
      return false;
    }
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
       vector<int> ans(n,0);
       int start=0;
       for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans[start++]=nums[i];
            }
       }
        return ans;
    }
};