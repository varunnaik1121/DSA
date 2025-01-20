class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int startColor=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        q.push({sr,sc});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            image[row][col]=color;
            int delRow[]={+1,-1,0,0};
            int delCol[]={0,0,+1,-1};
            for(int i=0;i<4;i++){
                int tRow=row+delRow[i];
                int tCol=col+delCol[i];
                if(tRow>=0 && tRow<n && tCol>=0 && tCol<m && image[tRow][tCol]!=color && image[tRow][tCol]==startColor){
                     image[tRow][tCol]=color;
                     q.push({tRow,tCol});
                }
            }
            
        }
        return image;

    }
};