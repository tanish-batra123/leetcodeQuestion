class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream ss(s);
        vector<string> res;
        while (ss >> word) {
            res.push_back(word);
        }
        string ans = "";
        reverse(res.begin(), res.end());

        for (int i = 0; i < res.size(); i++) {
            if (i != res.size() - 1) {
                ans += res[i] + " ";
            } else {
                ans += res[i];
            }
        }

        return ans;
    }
};