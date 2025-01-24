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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        DisjointSet ds(n*m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                int delRow[]={+1,-1,0,0};
                int delCol[]={0,0,-1,+1};
                for(int k=0;k<4;k++){
                    int tRow=delRow[k]+i;
                    int tCol=delCol[k]+j;
                    if(tRow>=0 && tRow<n && tCol>=0 && tCol<m && grid[tRow][tCol]==1){
                        int node1=tRow*n+tCol;
                        int node2=i*n+j;
                        ds.unionBySize(node1,node2);
                    }
                }
            }
        }
        //created a graph with the connected comps
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) continue;
        set<int> st;
                // notVisited=false;
                 int delRow[]={+1,-1,0,0};
                int delCol[]={0,0,-1,+1};
                for(int k=0;k<4;k++){
                    int tRow=delRow[k]+i;
                    int tCol=delCol[k]+j;
                    if(tRow>=0 && tRow<n && tCol>=0 && tCol<m && grid[tRow][tCol]==1){
                        int node1=tRow*n+tCol;
                        st.insert(ds.findUParent(node1));
                       
                       
                    }
                }
                int temp=1;
                for(auto it:st){
                    temp+=ds.size[it];

                }
                ans=max(ans,temp);
                
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUParent(i)]);
        }
        
        return ans;
    }
};