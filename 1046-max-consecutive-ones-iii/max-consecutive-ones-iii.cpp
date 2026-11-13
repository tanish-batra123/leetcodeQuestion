class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i = 0;
        int j = 0;
        int zeros = 0;
        int maxlen = 0;
        while (j < arr.size()) {
            if (arr[j] == 0)
                zeros++;

            while (zeros > k) {
                if (arr[i] == 0) {
                    zeros--;
                }
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};