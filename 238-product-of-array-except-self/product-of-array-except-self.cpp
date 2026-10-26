class Solution {
public:
    vector<int> productExceptSelf(vector<int>&arr) {
        int n=arr.size();
        vector<int>prefix(n);
        vector<int>suffix(n);

        vector<int>ans(n);
        
        prefix[0]=1;
        suffix[n-1]=1;

        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]*arr[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*arr[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }

        return ans;




    }
};