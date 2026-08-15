class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> arr(200001,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int index=nums[i]+100000;
            cout<<"index is "<<index<<endl;
            arr[index]+=1;
        }
        int cnt=0;
        for(int i=200000;i>=0;i--){
            cnt+=arr[i];
            if(cnt>=k){
                return i-100000;
            }
        }
        return 0;
    }
};