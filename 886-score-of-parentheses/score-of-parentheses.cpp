class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;
        for (char ch : s) {
            if (ch == '(') {
                st.push(0);
            } else {

                int currScore = st.top();
                st.pop();
                int value;
                if (currScore == 0) {
                    value = 1;
                } 
                else {
                    value = currScore * 2;
                }

                if(!st.empty()){
                    int parent=st.top();
                    st.pop();
                    st.push(parent + value);
                }else{
                    st.push(value);
                }

            }
        }
        return st.top();
    }
};