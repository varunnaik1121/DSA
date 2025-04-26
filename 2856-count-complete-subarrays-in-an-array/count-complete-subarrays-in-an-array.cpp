class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //find the distinct element in the whole array and then mathc that 

        //
        unordered_set<int> st(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(temp.size()==st.size()){
                    ans++;
                }
            }
        }
        return ans;

    }
};