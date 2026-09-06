class Solution {
public:

    int solve(int i,int j,string s, string t,vector<vector<int>>&dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=solve(i+1,j,s,t,dp)+solve(i+1,j+1,s,t,dp);
        }
        return dp[i][j]=solve(i+1,j,s,t,dp);

    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t,dp);
    }
};