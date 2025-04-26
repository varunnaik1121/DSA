class Solution {
    private:
        int getDigitSum(int n){
            int sum=0;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            return sum;
        }
public:
    int countLargestGroup(int n) {
        unordered_map <int,int> mpp;
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            int digitSum=getDigitSum(i);
            mpp[digitSum]++;
            maxi=max(maxi,mpp[digitSum]);
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==maxi){
                ans++;
            }
        }
        return ans;
    }
};