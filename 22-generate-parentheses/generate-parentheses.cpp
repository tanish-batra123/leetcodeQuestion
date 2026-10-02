class Solution {
public:
    bool isValid(string res) {
        int cnt = 0;
        for (char ch : res) {
            if (ch == '(')
                cnt++;
            else
                cnt--;
            if (cnt < 0)
                return false;
        }

        return cnt == 0;
    }
    void solve(int n, string res, vector<string>& ans) {
        if (n < 0)
            return;
        if (res.size() == 2 * n) {
            if (isValid(res)) {
                ans.push_back(res);
            }
            return;
        }

        res.push_back(')');
        solve(n, res, ans);
        res.pop_back();
        res.push_back('(');
        solve(n, res, ans);
        res.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};