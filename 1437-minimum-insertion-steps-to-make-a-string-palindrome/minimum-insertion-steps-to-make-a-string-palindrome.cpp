class Solution {
public:
    int lpSubse(int i, int j, string& s, vector<vector<int>>& dp) {

        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + lpSubse(i + 1, j - 1, s, dp);
        }

        return dp[i][j] =max(lpSubse(i + 1, j, s, dp), lpSubse(i, j - 1, s, dp));
    }

    int minInsertions(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int length = lpSubse(0, n - 1, s, dp);
        return n - length;
    }
};