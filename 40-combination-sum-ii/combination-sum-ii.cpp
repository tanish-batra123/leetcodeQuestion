
class Solution {
public:
    void solve(vector<int>& arr, vector<int>& small, vector<vector<int>>& big,
               int sum, int target, int idx) {
        if (sum == target) {
            big.push_back(small);
            return;
        }
        if (sum > target)
            return;
            int prev=-1;

        for (int i = idx; i < arr.size(); i++) {

            if (prev==-1||arr[i] != prev) {

                small.push_back(arr[i]);
                solve(arr, small, big, sum + arr[i], target, i + 1);
                small.pop_back();
                prev=arr[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> small;
        vector<vector<int>> big;
           sort(arr.begin(),arr.end());
        solve(arr, small, big, 0, target, 0);
        return big;
    }
};
