class Solution {
    private:
        void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int &v,int &u,int node){
            v++;
            u+=adj[node].size();
            visited[node]=true;
            for(auto it:adj[node]){
                if(!visited[it]){
                    dfs(adj,visited,v,u,it);
                }
            }
        }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                int v=0;
                int e=0;
                dfs(adj,visited,v,e,i);
                if((v*(v-1))/2==e/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};