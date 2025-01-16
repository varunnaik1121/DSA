class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size(), res=0;
        //If both arrays are even length then xor will cancel out each element
        if(s1 % 2 == 0 && s2 % 2 == 0) return 0;
        //if nums2 is odd length then nums1 element will remain once
        if(s2 % 2 != 0) {
            for(int x:nums1) res ^= x;
        }
        //if nums1 is odd length then nums2 element will remain once
        if(s1 % 2 != 0) {
            for(int x:nums2) res ^= x;
        }
        return res;
    }
};