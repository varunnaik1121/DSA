class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[] (vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            int first=ans.back()[0];
            int second=ans.back()[1];
            if(second>=intervals[i][0]){
                ans.back()[1]=max(intervals[i][1],second);
                
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};