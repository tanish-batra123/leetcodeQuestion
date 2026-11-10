class Solution {
public:
    int cnt = 0;
    void merge(vector<int>& arr, int low, int mid, int high) {
        int i = 0;
        int j = 0;
        int k = low;
        vector<int> left;
        vector<int> right;

        for (int i = low; i <= mid; i++) {
            left.push_back(arr[i]);
        }
        for (int i = mid + 1; i <= high; i++) {
            right.push_back(arr[i]);
        }

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i];
                i++;
            } else {
                arr[k++] = right[j];
                j++;
            }
        }

        while (i < left.size()) {
            arr[k++] = left[i];
            i++;
        }
        while (j < right.size()) {
            arr[k++] = right[j];
            j++;
        }
    }

    void countRevPairs(vector<int>& arr, int low, int mid, int high) {
        int j = mid + 1;
         for (int i = low; i <= mid; i++) {

            while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
              j++;
            }
            cnt+=j-(mid+1);
        }
    }

    void merge_sort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        countRevPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return cnt;
    }
};