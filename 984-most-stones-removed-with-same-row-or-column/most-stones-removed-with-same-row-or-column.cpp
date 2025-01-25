class DisjointSet{
    public: 
        vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findUParent(int node){
            if(node==parent[node]){
                return node;
            }
            //path compression
            return parent[node]=findUParent(parent[node]);
        }
        
        void unionBySize(int u,int v){
            int ulp_u=findUParent(u);
            int ulp_v=findUParent(v);
            if(ulp_v==ulp_u) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }else{
                parent[ulp_v]=ulp_u;
               size[ulp_u]+=size[ulp_v];
            }
        }
    
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    ds.unionBySize(i,j);
                }
            }
        }
        int comps=0;
        for(int i=0;i<n;i++){
            if(ds.findUParent(i)==i){
                comps++;
            }
        }
        return n-comps;
    }
};