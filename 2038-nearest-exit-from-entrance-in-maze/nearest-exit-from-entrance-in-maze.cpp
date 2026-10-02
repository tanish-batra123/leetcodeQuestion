class Solution {
public:
    bool isExist(int row, int col, int m, int n) {
        return row == 0 || row == m - 1 || col == 0 || col == n - 1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int sr = entrance[0];
        int sc = entrance[1];
        int minimumSteps = INT_MAX;

        q.push({0, {sr, sc}});
        visited[sr][sc] = 1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto it = q.front();
            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            if ((r!=sr || c!=sc)  && isExist(r, c, m, n)) {
                minimumSteps = min(minimumSteps, steps);
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !visited[nr][nc] && maze[nr][nc] != '+') {
                        visited[nr][nc]=1;
                    q.push({steps + 1, {nr, nc}});
                }
            }
        }

        return minimumSteps==INT_MAX?-1:minimumSteps;
    }
};