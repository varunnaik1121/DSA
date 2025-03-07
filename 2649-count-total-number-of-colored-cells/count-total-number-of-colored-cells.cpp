class Solution {
public:
    long long coloredCells(int n) {
       long long ans= 1+4*(((long long) n*(n-1))/2);
       return ans;
    }
};