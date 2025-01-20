class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int startColor=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> temp(n,vector<int> (m));
        for(int i=0;i<image.size();i++){
            for(int j=0;j<m;j++){
                temp[i][j]=image[i][j];
            }
        }
    //   if(image[sr][sc]==1){
          q.push({sr,sc});
    //   }
        // int n=image.size();
        // int m=image[0].size();
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            temp[row][col]=color;
            int delRow[]={+1,-1,0,0};
            int delCol[]={0,0,+1,-1};
            for(int i=0;i<4;i++){
                int tRow=row+delRow[i];
                int tCol=col+delCol[i];
                if(tRow>=0 && tRow<n && tCol>=0 && tCol<m && temp[tRow][tCol]!=color && temp[tRow][tCol]==startColor){
                     image[tRow][tCol]=color;
                     q.push({tRow,tCol});
                }
            }
            
        }
        return temp;

    }
};