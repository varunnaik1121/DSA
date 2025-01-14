class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,path,check,graph);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
            return ans;
    }
    bool dfs(int node,vector<int> &vis,vector<int> &path,vector<int> &check,vector<vector<int>> &graph){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto it:graph[node]){
           
             if(!vis[it]){
                if(dfs(it,vis,path,check,graph)==true) return true;
            }else if(path[it]==1){
                return true;
            }
           
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
};