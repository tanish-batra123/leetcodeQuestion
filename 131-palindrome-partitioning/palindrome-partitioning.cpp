class Solution {
public:
vector<vector<string>>ans;
    void solve(int i,string &s,vector<vector<int>>&dp,vector<string>&temp) {
        int n=s.size();
      if(i==n){
         ans.push_back(temp);
         return;
      }
      for(int j=i;j<n;j++){
        if(dp[i][j]==1){
            temp.push_back(s.substr(i,j-i+1));
            solve(j+1,s,dp,temp);
            temp.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (len == 1)
                    dp[i][i] = 1;
                else if (len == 2 && s[i] == s[j]) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                }
            }
        }
        vector<string>temp={};
        solve(0,s,dp,temp);
        return ans;
    }
    };