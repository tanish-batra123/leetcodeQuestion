class Solution {
public:
    void solve(string s, string res, vector<string>& ans, int idx,
               int segment) {

        if (segment == 4) {
            if (idx == s.size()) {
                ans.push_back(res);
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            string num = s.substr(idx, i + 1);
            if (idx + i + 1 > s.size())break;
                
            int val = std::stoi(num);
            if (val >= 0 && val <= 255) {
                string oldres = res;
                if (num.size() > 1 && num[0] == '0')
                    continue;
                if (segment > 0)res += ".";
                
                res += num;
                solve(s, res, ans, idx + num.size(), segment + 1);
                res = oldres;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string res = "";

        solve(s, res, ans, 0, 0);
        return ans;
    }
};