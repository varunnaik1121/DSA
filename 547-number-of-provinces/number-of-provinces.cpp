class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findUParent(int node){
            if(node==parent[node]){
                return node;
            }
            //path compression
            return parent[node]=findUParent(parent[node]);
        }
        
        void rankByUnion(int u,int v){
            int ulp_u=findUParent(u);
            int ulp_v=findUParent(v);
            if(ulp_v==ulp_u) return;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    ds.rankByUnion(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            if(ds.findUParent(i)==i){
                ans++;
            }
        }
        return ans;
    }
};