class Solution {
public:
        
    int numRescueBoats(vector<int>& people, int limit) {
        
       sort(people.begin(),people.end());
       int n=people.size();
       int start=0,end=n-1;
       int ans=0;
       while(start<=end){
            int sum=people[start]+people[end];
            if(sum<=limit){
                ans++;
                start++;
                end--;
            }else{
                ans++;
                end--;
            }
       }
       return ans;
    }
};