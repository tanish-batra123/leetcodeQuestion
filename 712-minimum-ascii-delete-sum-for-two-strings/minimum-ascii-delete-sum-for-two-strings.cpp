class Solution {
public:

int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i==s1.size()||j==s2.size())return 0;
      if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]){
        int asciiVal=s1[i];
        return dp[i][j]=asciiVal+solve(i+1,j+1,s1,s2,dp);
    }
    return dp[i][j]=max(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
}


    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int shortestCommonSubASCII=solve(0,0,s1,s2,dp);

        int asciiS1=0;
        int asciiS2=0;

        for(char ch:s1){
            asciiS1+=ch;
        }
          for(char ch:s2){
            asciiS2+=ch;
        }
        return (asciiS1-shortestCommonSubASCII)+(asciiS2-shortestCommonSubASCII);

    }
};