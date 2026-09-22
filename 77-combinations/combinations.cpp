class Solution {
public:
    void helper(int n, vector<int>& small, vector<vector<int>>& big,int idx, int k) {
        if (small.size() == k) {
            big.push_back(small);
            return;
        }
        for (int i = idx; i <= n; i++) {
            small.push_back(i);
            helper(n, small, big, i+1,k);
            small.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> small;
        vector<vector<int>> big;
        helper(n, small, big, 1,k);
        return big;
    }
};