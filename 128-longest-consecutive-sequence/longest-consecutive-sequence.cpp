class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=0;
        for(auto i:st){
            if(st.find(i-1)==st.end()){
                int temp=i;
                int cnt=0;
                while(st.find(temp++)!=st.end()){
                    cnt++;
                }
                ans=max(ans,cnt);
                
            }
        }
        return ans;
    }
};