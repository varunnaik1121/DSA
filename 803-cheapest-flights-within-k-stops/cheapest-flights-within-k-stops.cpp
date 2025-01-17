class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        //created a graph with adjacency list with weight
        for(auto it:flights){
            int from=it[0];
            int to=it[1];
            int cost=it[2];
            adj[from].push_back({to,cost});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
         dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int nd=it.second.first;
            int cost=it.second.second;
           
            if(stops>k){
                break;
            }
            for(auto node:adj[nd]){
                int v=node.first;
                int w=node.second;
                if(cost+w<dist[v] && stops<=k){
                    dist[v]=cost+w;
                    q.push({stops+1,{v,cost+w}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};