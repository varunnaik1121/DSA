class Solution {
    bool isPossible(long long time,vector<int> &ranks,int cars){
        long long ans=0;
        for(int i=0;i<ranks.size();i++){
            ans+=sqrt(time/ranks[i]);
            
            if(ans>=cars) break;
        }
        return ans>=cars;
        
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1;
        long long high=0;
        int maxi=0;
        high=1e14;
        long long ans=1e14;
        while(low<=high){
            long long mid=(low+high)/2;
            if(isPossible(mid,ranks,cars)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};