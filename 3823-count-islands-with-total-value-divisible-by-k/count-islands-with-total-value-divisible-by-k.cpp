class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>>& grid,
             vector<vector<int>>& visited, int k, int& cnt) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        q.push({sr, sc});
        visited[sr][sc] = 1;
        long long sum = 0;
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto temp = q.front();
            int r = temp.first;
            int c = temp.second;
            sum += grid[r][c];
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !visited[nr][nc]  && grid[nr][nc]!=0) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        if (sum % k == 0)
            cnt++;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j]!=0) {
                    bfs(i, j, grid, visited, k, cnt);
                }
            }
        }
        return cnt;
    }
};