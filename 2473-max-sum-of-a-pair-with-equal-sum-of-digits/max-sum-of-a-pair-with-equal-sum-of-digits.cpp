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
        map<int,priority_queue<int,vector<int>,greater<int>>> mpp;
        for(int i=0;i<nums.size();i++){
            int sum=sumOfDigits(nums[i]);
            mpp[sum].push(nums[i]);
            if(mpp[sum].size()>2){
                mpp[sum].pop();
            }
        }
        int maxi=-1;
        for(auto it:mpp ){
            if(it.second.size()>=2){
               int num1=it.second.top();it.second.pop();
               int num2=it.second.top();it.second.pop();
               maxi=max(maxi,num1+num2);
            }
        }
        return maxi;

        
    }
};