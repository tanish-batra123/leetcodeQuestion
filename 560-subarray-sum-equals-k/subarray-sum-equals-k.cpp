class Solution {
public:
    int subarraySum(vector<int>&arr, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k)cnt++;

            if(mpp.find(sum-k)!=mpp.end()){
                cnt+=mpp[sum-k];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};