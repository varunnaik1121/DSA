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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras=0;
       for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(ds.findUParent(u)==ds.findUParent(v)){
            extras++;
        }else{
            ds.rankByUnion(u,v);
        }
       }
       int components=0;
       for(int i=0;i<n;i++){
        if(ds.findUParent(i)==i){
            components++;
        }
       }
       if(extras>=components-1){
            return components-1;
       }
       return -1;

    }
};