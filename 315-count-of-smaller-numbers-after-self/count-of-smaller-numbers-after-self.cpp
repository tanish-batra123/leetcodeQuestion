class Solution {
public:
    void merge(vector<int>& arr, vector<int>& indices, vector<int>& ans,
               int low, int mid, int high) {
        int i = 0;
        int j = 0;
        int k = low;
        vector<int> left;
        vector<int> right;
        vector<int> leftIdx, rightIdx;

        for (int i = low; i <= mid; i++) {
            left.push_back(arr[i]);
            leftIdx.push_back(indices[i]);
        }
        for (int i = mid + 1; i <= high; i++) {
            right.push_back(arr[i]);
            rightIdx.push_back(indices[i]);
        }
        int count = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                indices[k] = leftIdx[i];
                ans[leftIdx[i]] += count;
                arr[k++] = left[i];
                i++;
            } else {
                indices[k] = rightIdx[j];
                arr[k++] = right[j];
                count++;
                j++;
            }
        }

        while (i < left.size()) {
            ans[leftIdx[i]] += count;

            arr[k] = left[i];
            indices[k] = leftIdx[i];
            i++;
            k++;
        }
        while (j < right.size()) {

            arr[k] = right[j];
            indices[k] = rightIdx[j];
            j++;
            k++;
        }
    }

    void merge_sort(vector<int>& arr, vector<int>& indices, vector<int>& ans,
                    int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        merge_sort(arr, indices, ans, low, mid);
        merge_sort(arr, indices, ans, mid + 1, high);
        merge(arr, indices, ans, low, mid, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> indices(nums.size());
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            indices[i] = i;
        }
        merge_sort(nums, indices, ans, 0, nums.size() - 1);
        return ans;
    }
};