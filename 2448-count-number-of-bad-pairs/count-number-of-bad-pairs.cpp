class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        long long good_pairs=0;
        int n=nums.size();
       long long total_pairs=0;
       for(int i=0;i<n;i++){
        total_pairs+=i;
       }
        for(int i=0;i<n;i++){
            int temp=nums[i]-i;
            good_pairs+=mpp[temp];
            mpp[temp]++;
        }
        return total_pairs-good_pairs;
    }
};