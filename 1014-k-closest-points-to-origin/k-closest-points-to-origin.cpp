class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,int>> pq;
       int n=points.size();
       for(int i=0;i<n;i++){
        int first=points[i][0];
        int second=points[i][1];
        int temp=abs(pow(first,2)+pow(second,2));
        pq.push({temp,i});
        if(pq.size()>k){
            pq.pop();
        }
       }
       vector<vector<int>> ans;
       while(pq.size()>0){
        ans.push_back(points[pq.top().second]);
        pq.pop();
       }
       return ans;

    }
};