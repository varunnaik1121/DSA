class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                
                //4 sides
                int trow=it.first;
                int tcol=it.second;
            if(trow+1<grid.size() && grid[trow+1][tcol]==1){
                q.push({trow+1,tcol});
                grid[trow+1][tcol]=2;
            }
            //right
            if(tcol+1<grid[0].size() && grid[trow][tcol+1]==1){
                q.push({trow,tcol+1});
                grid[trow][tcol+1]=2;
            }
            if(tcol-1>=0 && grid[trow][tcol-1]==1){
                q.push({trow,tcol-1});
                grid[trow][tcol-1]=2;
            }
            if(trow-1>=0 && grid[trow-1][tcol]==1){
                q.push({trow-1,tcol});
                grid[trow-1][tcol]=2;
            }
           
            }
             ans++;
            
            
           
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return max(0,ans-1);

    }
};