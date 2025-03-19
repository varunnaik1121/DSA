class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        int minPosIdx=-1;
        int minNegIdx=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>0){
                minPosIdx=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]<0){
                minNegIdx=mid;
                start=mid+1;

            }else{
                end=mid-1;
            }
        }
        cout<<minNegIdx<<" "<< minPosIdx<<endl;
        if(minPosIdx==-1) return minNegIdx+1;
        if(minNegIdx==-1) return n-minPosIdx;
        return max(minNegIdx+1,n-minPosIdx);

    }
};