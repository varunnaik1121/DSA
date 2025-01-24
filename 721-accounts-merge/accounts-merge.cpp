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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailToNode;
        //created the mapping deleted the duplicates
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailToNode.find(mail)==mailToNode.end()){
                    mailToNode[mail]=i;
                }else{
                    ds.rankByUnion(i,mailToNode[mail]);
                }
            }
        }
        vector<vector<string>> temp(n);
        for(auto it:mailToNode){
            string mail=it.first;
            int node=it.second;
            int uParent=ds.findUParent(node);
            temp[uParent].push_back(mail);

        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(temp[i].size()==0) continue;
          vector<string> curr=temp[i];
          sort(curr.begin(),curr.end());
          vector<string> newArr;
          newArr.push_back(accounts[i][0]);
          for(auto it:curr){
            newArr.push_back(it);
          }
          ans.push_back(newArr);
        }
        return ans;

    }
};