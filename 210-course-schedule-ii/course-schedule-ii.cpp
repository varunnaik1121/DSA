class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int V=numCourses;
        for(auto node:prerequisites){
            int from=node[0];
            int to=node[1];
            adj[from].push_back(to);
        }
        //lets do khans algo
        int cnt=0;
        vector<int> inDegree(numCourses,0);
        for(auto node:adj){
            for(auto it:node){
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};