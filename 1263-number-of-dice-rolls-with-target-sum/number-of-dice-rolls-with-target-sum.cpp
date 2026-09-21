class Solution {
public:
   int mod = 1e9 + 7;
    // void solve(int src,int n,int k,int target,int sum,int &ans){
    //     if(sum>target)return;
    //     if(src == n){
    //         if(sum==target){
    //          ans++;
    //          return;
    //      }

    //     }

    //     for(int i=1;i<=k;i++){
    //      solve(src+1,n,k,target,sum+i,ans);
    //     }

    // }

    long long solve(int src, int n, int k, int target, int sum, vector<vector<int>>&dp) {
       
        if (src == n) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        if(sum >target)return 0;
         if(dp[src][sum]!=-1)return dp[src][sum];
        
        long long ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += solve(src + 1, n, k, target, sum + i,dp);
            ans=ans%mod;
        }
        return dp[src][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
       
     
        vector<vector<int>>dp(31,vector<int>(1001,-1));
        long long ans=solve(0, n, k, target, 0,dp);
        return ans;
    }
};