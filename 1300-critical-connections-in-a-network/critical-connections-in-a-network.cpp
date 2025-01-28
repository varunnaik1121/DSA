class Solution {
    private:
        int timer=0;
    private:
        void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis,int in[],int low[],vector<vector<int>> &bridges){
            vis[node]=1;
            low[node]=in[node]=timer;
            timer++;
            for(auto it:adj[node]){
                if(it==parent){
                    continue;
                }else if(!vis[it]){
                    dfs(it,node,adj,vis,in,low,bridges);
                    low[node]=min(low[node],low[it]);

                    //check if its the bridge
                    if(in[node]<low[it]){
                        bridges.push_back({node,it});
                    }
                }else{
                    low[node]=min(low[node],low[it]);
                }
            }
        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int in[n];
        int low[n];
        vector<vector<int>> ans;
        //created the adjacency list 
        dfs(0,-1,adj,vis,in,low,ans);
        return ans;

    }
};