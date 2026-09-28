class Solution {
public:
    int maxProfit(vector<int>&arr) {
        int maxiProfit=0;
        int lowestPrice=arr[0];
         for(int i=0;i<arr.size();i++){
            lowestPrice=min(lowestPrice,arr[i]);
            int profit=arr[i]-lowestPrice;
            maxiProfit=max(maxiProfit,profit);

         }
         return maxiProfit;
    }
};