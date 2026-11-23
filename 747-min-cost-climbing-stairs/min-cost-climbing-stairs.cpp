class Solution {
public:
    int solve(int i, vector<int>& arr, int n, vector<int>& dp) {
        if (i == 0 || i == 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int onestep = arr[i - 1] + solve(i - 1, arr, n, dp);
        int secondstep = arr[i - 2] + solve(i - 2, arr, n, dp);

        return dp[i] = min(onestep, secondstep);
    }
    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();
        // vector<int> dp(n + 1, -1);
        // int ans = solve(n, arr, n, dp);
        // dp[0]=0;
        int prev2=0;
        int prev1=0;
        // for (int i = 2; i <= n;i++) {
        //     int onestep = arr[i - 1] + dp[i-1];
        //     int secondstep = arr[i - 2] + dp[i-2];
        //      dp[i] = min(onestep, secondstep);
        // }

        for(int i=2;i<=n;i++){
             int onestep = arr[i - 1] + prev1;
             int secondstep = arr[i - 2] + prev2;
             int curr=min(onestep,secondstep);
             prev2=prev1;
             prev1=curr;
        }

        return prev1;
    }
};