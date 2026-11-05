class Solution {
public:
    int minPairSum(vector<int>&arr) {
        sort(arr.begin(),arr.end());
        int maxpairsum=0;
        for(int i=0;i<arr.size()/2;i++){
            maxpairsum=max(maxpairsum,arr[i]+arr[arr.size()-i-1]);
        }
        return maxpairsum;
    }
};