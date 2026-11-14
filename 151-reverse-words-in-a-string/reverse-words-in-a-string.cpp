// class Solution {
// public:
//     string reverseWords(string s) {
//         string word;
//         stringstream ss(s);
//         vector<string> res;
//         while (ss >> word) {
//             res.push_back(word);
//         }
//         string ans = "";
//         reverse(res.begin(), res.end());

//         for (int i = 0; i < res.size(); i++) {
//             if (i != res.size() - 1) {
//                 ans += res[i] + " ";
//             } else {
//                 ans += res[i];
//             }
//         }

//         return ans;
//     }
// };



















class Solution {
public:
    string reverseWords(string s) {
        string snew;
        vector<string>res;
       
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                snew+=s[i];
            }else if(!snew.empty() && snew.back() != ' '){
                snew+=' ';
            } 
        }
        if (!snew.empty() && snew.back() == ' ') {
            snew.pop_back();
        }
       

       string word = "";

        for (int i = 0; i < snew.size(); i++) {
            if (snew[i] == ' ') {
                res.push_back(word);
                word = "";
            } 
            else {
                word += snew[i];
            }
        }

        if (!word.empty()) {
            res.push_back(word);
        }
        reverse(res.begin(), res.end());
        string ans = "";

        for (int i = 0; i < res.size(); i++) {
            ans += res[i];

            if (i != res.size() - 1) {
                ans += ' ';
            }
        }

        return ans;

    }
};