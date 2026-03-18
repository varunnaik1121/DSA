class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0;
        int end=0;
        int n=nums.size();
       while(start<n && end<n){
            while(start<n && nums[start]!=0){
                start++;

            }
            end=start+1;
            while(end<n && nums[end]==0) end++;
            if(start<n && end<n){
                swap(nums[start],nums[end]);
            }
            start++;
            end++;
       } 
    }
};