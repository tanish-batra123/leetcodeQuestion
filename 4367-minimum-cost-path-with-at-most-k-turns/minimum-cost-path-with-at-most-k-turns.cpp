class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    5, vector<int>(k + 1, 1e9)
                )
            )
        );

       priority_queue<
    pair<int, vector<int>>,
    vector<pair<int, vector<int>>>,
    greater<pair<int, vector<int>>>
> pq;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        pq.push({grid[0][0], {0, 0, 4, 0}});
     

        int mincost = INT_MAX;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int r = pq.top().second[0];
            int c = pq.top().second[1];
            int dir = pq.top().second[2];
            int turns = pq.top().second[3];

            pq.pop();

            if (r == m - 1 && c == n - 1) {
                mincost = min(mincost, cost);
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                
                if (nr >= m || nr < 0 || nc >= n || nc < 0)
                    continue;

                int newturns = turns;

                if (dir != 4 && dir != i) {
                    newturns++;
                }

                if (newturns > k)
                    continue;
                  int newcost=cost + grid[nr][nc];

                if ( newcost < dist[nr][nc][i][newturns]) {
                     dist[nr][nc][i][newturns] = newcost;
                    pq.push({
                        newcost,
                        {nr, nc, i, newturns}
                    });
                }
            }
        }

        return mincost == INT_MAX ? -1 : mincost;
    }
};