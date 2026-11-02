class Solution {
public:
    void solve(int idx, string num, int target, string& temp, long long val,
               long long prevval, vector<string>& ans) {
        if (idx == num.size()) {
            if (val == target) {
                ans.push_back(temp);
            }
            return;
        }

        long long currval = 0;
        int len = temp.size();

        for (int i = idx; i < num.size(); i++) {
            currval = currval * 10 + num[i] - '0';
            string s = to_string(currval);

            if (i > idx && num[idx] == '0')
                break;

            if (idx == 0) {
                temp += s;
                solve(i + 1, num, target, temp, currval, currval, ans);
                temp.resize(len);
            } else {
                temp += "+" + s;
                solve(i + 1, num, target, temp, val + currval,
                      currval, ans);
                temp.resize(len);

                temp += "-" + s;
                solve(i + 1, num, target, temp, val - currval,
                      -currval, ans);
                temp.resize(len);

                temp += "*" + s;
                solve(i + 1, num, target, temp,
                      val - prevval + prevval * currval,
                      prevval * currval, ans);
                temp.resize(len);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp = "";
        solve(0, num, target, temp, 0, 0, ans);
        return ans;
    }
};