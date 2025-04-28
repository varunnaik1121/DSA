class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        int i=0,j=0;
        int n=nums.size();
        int uniqCount=0;
        int ans=0;
        while(i<n && j<n){
            mpp[nums[j]]++;
            if(mpp[nums[j]]==1){
                uniqCount++;
            }
            while(uniqCount==st.size()){
                ans+=n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    uniqCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};