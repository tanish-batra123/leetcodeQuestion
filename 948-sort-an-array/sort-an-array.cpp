class Solution {
public:
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

    void merge_sort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
           
        int mid = low + (high - low) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    vector<int> sortArray(vector<int>& arr) {
        merge_sort(arr, 0, arr.size() - 1);
        return arr;
    }
};