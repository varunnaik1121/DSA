class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            int prevDiff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            //4 paths i can travel
            int delRow[]={+1,-1,0,0};
            int delCol[]={0,0,-1,+1};
            for(int i=0;i<4;i++){
                int tRow=row+delRow[i];
                int tCol=col+delCol[i];
               
                if(tRow>=0 && tRow<n && tCol>=0 && tCol<m && max(abs(heights[tRow][tCol]-heights[row][col]),prevDiff)<dist[tRow][tCol]){
                     
                    pq.push({max(abs(heights[tRow][tCol]-heights[row][col]),prevDiff),{tRow,tCol}});
                    dist[tRow][tCol]=max(abs(heights[tRow][tCol]-heights[row][col]),prevDiff);
                }
            }
        }
        return dist[n-1][m-1];
    }
};