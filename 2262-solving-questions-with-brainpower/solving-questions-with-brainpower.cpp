class Solution {
    long long solve(int i,vector<vector<int>> &questions,vector<long long> &dp){
        int n=questions.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long taken=questions[i][0]+solve(i+questions[i][1]+1,questions,dp);
        long long notTaken=solve(i+1,questions,dp);
        return dp[i]=max(taken,notTaken);

    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n =questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,dp);
    }
};