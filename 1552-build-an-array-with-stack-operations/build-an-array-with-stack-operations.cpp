class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int top = target[target.size() - 1];
        int first = target[0];

        int j=0;
        for (int i = 1; i <= top; i++) {
            if(i==target[j]){
                j++;
                ans.push_back("Push");
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};