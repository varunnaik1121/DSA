class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long>> pq;
        for(int num:nums){
            pq.push(num);
        }
        unsigned long long ans=0;
        while(pq.size()>=2 && pq.top()<k){
            unsigned long long num1=pq.top();
            pq.pop();
            unsigned long long num2=pq.top();
            pq.pop();
            unsigned long long temp=min(num1,num2)*2;
            pq.push(temp+max(num1,num2));
            ans++;
        }
        return ans;
    }
};