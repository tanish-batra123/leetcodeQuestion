class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colorOfStartingPixel=image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
      vector<vector<int>> visited(m , vector<int>(n, 0));
         visited[sr][sc]=1;
         int dr[4]={-1,1,0,0};
         int dc[4]={0,0,-1,1};
         while(!q.empty()){
            auto temp=q.front();
            int r=temp.first;
            int c=temp.second;
          
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<m && nr>=0 && nc<n && nc>=0 && !visited[nr][nc] && image[nr][nc]==colorOfStartingPixel){
                    visited[nr][nc]=1;
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
         }
         return image;
        

    }
};