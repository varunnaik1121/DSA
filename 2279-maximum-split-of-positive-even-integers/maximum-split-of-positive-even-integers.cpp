class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return {};
        long long i=2;
        vector<long long> ans;
        while(finalSum>0){
            if(i<=finalSum){
                ans.push_back(i);
                 finalSum-=i;
                i+=2;
            }else{
                ans.back()=ans.back()+finalSum;
                break;
            }
        }
        return ans;
    }
};