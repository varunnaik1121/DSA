class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(dfs(i,0,vis,graph)==false) return false;
            }
        }
        return true;
    }
    bool dfs(int node,int color,vector<int> &vis,vector<vector<int>> &graph){
        vis[node]=color;
        for(auto adjNode:graph[node]){
            if(vis[adjNode]==-1){
                if(dfs(adjNode,!color,vis,graph)==false) return false;
            }else if(vis[adjNode]==color) return false;
        }
        return true;
    }
};