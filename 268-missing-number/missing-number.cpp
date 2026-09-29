class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size();
        int totalSum=n*(n+1)/2;
         int currSum=0;
         for(int val:arr){
            currSum+=val;
         }
         return totalSum-currSum;
    }
};