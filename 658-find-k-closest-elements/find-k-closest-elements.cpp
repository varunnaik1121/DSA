class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int start=0,end=0;
        int n=arr.size();
        int maxi=INT_MAX;
        int sum=0;
        int startIdx=-1,endIdx=-1;
        while(end<n){
            sum+=abs(x-arr[end]);
            while(end-start+1>k){
                sum-=abs(x-arr[start]);
                start++;
            }
            if(end-start+1==k){
                if(sum<maxi){
                    maxi=sum;
                    startIdx=start;
                    endIdx=end;

                }
            }
            end++;
        }
        
        for(int i=startIdx;i<=endIdx;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};