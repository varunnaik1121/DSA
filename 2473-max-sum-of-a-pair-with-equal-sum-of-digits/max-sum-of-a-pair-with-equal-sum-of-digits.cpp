class Solution {
private:
    int sumOfDigits(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
       unordered_map<int,int> mpp;
       int maxi=-1;
       for(auto num:nums){
            int digitSum=sumOfDigits(num);
            if(mpp.find(digitSum)!=mpp.end()){
                maxi=max(maxi,num+mpp[digitSum]);
                mpp[digitSum]=max(num,mpp[digitSum]);
            }else{
                mpp[digitSum]=num;
            }
       }
       return maxi;

        
    }
};