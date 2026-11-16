class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int sr,
            int sc) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int p = 0;
        int edges = 0;

        q.push({sr, sc});
        visited[sr][sc] = 1;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            p += 4;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

              

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {
                    if (k == 0 || k == 2)
                        edges++;

                    if (!visited[nr][nc]) {
                        q.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }
        return p - edges * 2;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans += bfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};
