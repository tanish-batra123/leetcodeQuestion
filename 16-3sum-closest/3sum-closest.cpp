class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int closetSum = 0;
        int mindiff = INT_MAX;
        for (int p = 0; p < n; p++) {
            int i = p + 1;
            int j = n - 1;

            while (i < j) {
                int sum = 0;
                sum += arr[i] + arr[j] + arr[p];
                int diff = abs(sum - target);
                if (diff < mindiff) {
                    mindiff = diff;
                    closetSum=sum;
                }
                if (sum > target) {
                    j--;
                } else
                    i++;
            }
        }
        return closetSum;
    }
};