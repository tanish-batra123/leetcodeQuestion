class Solution {
public:
int solve(int i,vector<int>& arr, int amount,long long sum,vector<vector<int>>&dp){
    if(sum==amount)return 0;
    if(sum >amount||i==arr.size()) return 1e9;
    if(dp[i][sum]!=-1)return dp[i][sum];
    int take=1+solve(i,arr,amount,sum+arr[i],dp);
    int non_take=solve(i+1,arr,amount,sum,dp);

    return dp[i][sum]=min(take,non_take);

}
    int coinChange(vector<int>& arr, int amount) {
        // vector<int>dp(arr.size()+1,-1);
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(0,arr,amount,0,dp);
        return ans==1e9?-1:ans;
    }
};