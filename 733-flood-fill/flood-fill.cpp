class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int originalColor=grid[sr][sc];
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        queue<pair<int,int>>q;
        grid[sr][sc]=color;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc] == originalColor){
                  q.push({nr,nc});
                  visited[nr][nc]=1;
                  grid[nr][nc]=color;
                }
            }
        }

        return grid;

    }
};