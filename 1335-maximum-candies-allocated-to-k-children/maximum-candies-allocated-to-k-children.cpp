class Solution {
    long long isPossible(long long mid,vector<int> candies,long long k){
        long long  temp=0;
        for(int candie:candies){
            temp+=(candie/mid);
        }
        return temp;
       
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(isPossible(mid,candies,k)>=k){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};