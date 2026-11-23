class Solution {
public:
// int solve(int i,vector<int>& arr, int amount,long long sum,vector<vector<int>>&dp){
//     if(sum==amount)return 0;
//     if(sum >amount||i==arr.size()) return 1e9;
//     if(dp[i][sum]!=-1)return dp[i][sum];
//     int take=1+solve(i,arr,amount,sum+arr[i],dp);
//     int non_take=solve(i+1,arr,amount,sum,dp);

//     return dp[i][sum]=min(take,non_take);

// }
    int coinChange(vector<int>& arr, int amount) {
        // vector<int>dp(arr.size()+1,-1);
        int n=arr.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // int ans=solve(0,arr,amount,0,dp);
        // return ans==1e9?-1:ans;

      vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));
        for(int i=0;i<n;i++){
            dp[i][amount]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int sum=amount-1;sum>=0;sum--){
                int take=1e9;
                if(sum+(long long)arr[i] <=amount){
                  take=1+dp[i][sum+arr[i]];
                }
                int non_take=dp[i+1][sum];
                dp[i][sum]=min(take,non_take);
            }
        }
        return dp[0][0]==1e9?-1:dp[0][0];

        
    }
};