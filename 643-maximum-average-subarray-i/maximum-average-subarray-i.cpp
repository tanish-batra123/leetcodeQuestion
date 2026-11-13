class Solution {
public:
    double findMaxAverage(vector<int>&arr, int k) {
        int i = 0;
        int j = 0;
     double sum = 0;
        double maxsum = INT_MIN;

        while (j<arr.size()) {
            sum += arr[j];
            if (j - i + 1 == k) {
                maxsum = max(maxsum, sum);
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
        cout<<maxsum;

        return maxsum / k;
    }
};