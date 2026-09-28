class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxPro = 0;

       
        for (int i = 1; i < arr.size(); i++) {
            if(arr[i-1]<=arr[i]){
                maxPro+=arr[i]-arr[i-1];
            }
        }
        return maxPro;
    }
};