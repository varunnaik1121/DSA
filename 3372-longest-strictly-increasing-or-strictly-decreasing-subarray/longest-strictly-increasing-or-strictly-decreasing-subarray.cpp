class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxInc=INT_MIN;
        int temp=1;
       for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                temp+=1;
                  maxInc=max(maxInc,temp);
            }else{
                temp=1;
            }
       }
       
     
       temp=1;
       int maxDec=INT_MIN;
       for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
            temp+=1;
            maxDec=max(maxDec,temp);
        }else{
            temp=1;
        }
       }
       return max(1,max(maxDec,maxInc));
    }
};