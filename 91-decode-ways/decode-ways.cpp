class Solution {
public:
    int solve(int i, string& s, vector<int>& dp) {

        if (i == s.size())
            return 1;

        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int oneDigit = 0;
        oneDigit += solve(i + 1, s, dp);
        int secondDigit = 0;
        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) {
                secondDigit += solve(i + 2, s, dp);
            }
        }

        return dp[i] = oneDigit + secondDigit;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                dp[i] = 0;
        }
        // int ans = solve(0, s,dp);
        // return ans;

        for (int i = s.size()-1; i >=0; i--) {
              if (s[i] == '0') {
            continue;
        }
            int oneDigit = 0;
            oneDigit += solve(i + 1, s, dp);
            int secondDigit = 0;
            if (i + 1 < s.size()) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num >= 10 && num <= 26) {
                    
                 secondDigit += dp[i + 2];
                
                }
            }
            dp[i] = oneDigit + secondDigit;
        }

        return dp[0];
    }
};