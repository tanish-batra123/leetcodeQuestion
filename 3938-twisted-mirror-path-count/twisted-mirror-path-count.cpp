class Solution {
public:
int mod = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>>& grid, int m, int n, int dir,vector<vector<vector<int>>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n) return 0;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        int right = 0;
        int down = 0;
        if (grid[i][j] == 1) {
            if (dir == 1) {
                // right

                return dp[i][j][dir] = solve(i + 1, j, grid, m, n, 0,dp);
            } else {
                return dp[i][j][dir] = solve(i, j + 1, grid, m, n, 1,dp);
            }
        } else {
            right = solve(i, j + 1, grid, m, n, 1,dp);
            down = solve(i + 1, j, grid, m, n, 0,dp);
        }

        return dp[i][j][dir] = (right%mod)+(down%mod);
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
         ans+= solve(0, 0, grid, m, n,0,dp);
        //  ans+= solve(0, 0, grid, m, n,1);
        
        return ans % mod;
    }
};