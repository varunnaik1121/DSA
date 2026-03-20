class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> squares(n);
        int L=0,R=n-1;
        int tmp=n-1;
        while(L<=R){
            if(abs(nums[L])>abs(nums[R])){
                squares[tmp]=nums[L]*nums[L];
                L++;
            }else{
                squares[tmp]=nums[R]*nums[R];
                R--;
            }
            tmp--;
        }
        return squares;
    }
};