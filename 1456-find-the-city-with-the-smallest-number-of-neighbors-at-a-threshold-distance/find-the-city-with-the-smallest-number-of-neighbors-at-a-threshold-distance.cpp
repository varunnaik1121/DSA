class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n,vector<int> (n,INT_MAX));
        //created a bidirectional matrix of adjMat
        for(auto it:edges){
            adjMat[it[0]][it[1]]=it[2];
            adjMat[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            adjMat[i][i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(adjMat[i][k]==INT_MAX || adjMat[j][i]==INT_MAX) continue;
                    adjMat[j][k]=min(adjMat[j][k],adjMat[j][i]+adjMat[i][k]);
                }
            }
        }
        int city=-1;
        int mini=INT_MAX;
        
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(adjMat[i][j]!=INT_MAX && adjMat[i][j]<=distanceThreshold){
                    temp++;

                }
            }
            if(temp<=mini){
                mini=temp;
                city=i;
            }
        }
        return city;
    }
};