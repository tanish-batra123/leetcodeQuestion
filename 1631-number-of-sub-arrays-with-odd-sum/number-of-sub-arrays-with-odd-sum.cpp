class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int mod=1e9+7;
        mpp[0]=1;
        long long cnt=0;
        long long sum=0;
        int n=arr.size();
        long long total=(n*1LL*(n+1)/2)%mod;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int rem=sum%2;
            if(mpp.find(rem)!=mpp.end()){
              cnt=(cnt+mpp[rem])%mod;
            }
            mpp[rem]++;
        }

        return (total-cnt+mod)%mod;
    }
};