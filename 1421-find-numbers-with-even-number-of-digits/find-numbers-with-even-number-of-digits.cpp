class Solution {
    private:
        bool doesContainsEven(int num){
            int count=0;
            while(num>0){
                int rem=num%10;
                count++;
                num/=10;
                
            }
            return count%2==0;
        }
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto &num:nums){
            if(doesContainsEven(num)){
                ans++;
            }

        }
        return ans;
    }
};