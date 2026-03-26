class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int n=numbers.size();
        int end=n-1;
        while(start<n && start<end){
            int sum=numbers[start]+numbers[end];
            if(sum<target){
                start++;
            }else if(sum>target){
                end--;
            }else{
                return {start+1,end+1};
            }
        }
        return {-1,-1};
    }
};