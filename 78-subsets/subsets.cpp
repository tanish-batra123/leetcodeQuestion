class Solution {
public:
    void helper(vector<int>& arr, vector<int>& small, vector<vector<int>>& big,
                int idx) {
                    big.push_back(small);
        for (int i = idx; i < arr.size(); i++) {
            small.push_back(arr[i]);
            helper(arr, small,big,i+1);
            small.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> small={};
        vector<vector<int>> big;
        helper(arr, small, big, 0);
        return big;
    }
};