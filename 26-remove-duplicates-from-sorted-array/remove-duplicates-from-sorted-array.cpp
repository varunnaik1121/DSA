class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size()-1; 
       

        int temp=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[i+1]){
                nums[temp++]=nums[i];
            }
        }
        if(temp==0) return 1;
        if(nums[temp-1]!=nums[n]){
            nums[temp]=nums[n];
            temp++;
        }
        return temp;
        

    }
};