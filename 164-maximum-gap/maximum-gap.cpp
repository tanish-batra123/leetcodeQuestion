class Solution {
public:
    int maximumGap(vector<int>& arr) {
        if(arr.size()<2)return 0;
        int n=arr.size();
        int maxi=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
           maxi=max(maxi,arr[i+1]-arr[i]);
        }
        return maxi;
    }
};