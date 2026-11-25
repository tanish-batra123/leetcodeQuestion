class Solution {
public:
    int minimumSumSubarray(vector<int>& arr, int l, int r) {
        int minsum=INT_MAX;
        int n=arr.size();
         for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                int size = j - i + 1;

                if (size >= l && size <= r && sum > 0) {
                    minsum = min(minsum, sum);
                }
                
                if (size > r) break; 
            }
        }

        return minsum == INT_MAX ? -1 : minsum;
    }
};