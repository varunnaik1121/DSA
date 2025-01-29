class DisjointSet{
    public:
        vector<int> parent;
        vector<int> rank;
    
        DisjointSet(int n){
            rank.resize(n,0);
            parent.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUParent(int i){
            if(parent[i]!=i){
                parent[i]=findUParent(parent[i]);
            }
            return parent[i];
            
        }
        void join(int u,int v){
            int uPu=findUParent(u);
            int uPv=findUParent(v);
            if(rank[uPu]==rank[uPv]){
                parent[uPu]=uPv;
                rank[uPu]++;
            }else if(rank[uPu]>rank[uPv]){
                parent[uPv]=uPu;
                
            }else{
                parent[uPu]=uPv;
            }
        }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n+1);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                return edge;
            }
            ds.join(u,v);

        }
        return {};
    }
};