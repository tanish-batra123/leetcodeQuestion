class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ')') {
                string temp="";
                while (!st.empty() && st.top() != '(') {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                

                for(char c:temp){
                    st.push(c);
                }
            }
            st.push(ch);
        }
        string res="";
        while(!st.empty()){
            char x=st.top();
            if(x!='(' && x!=')')res+=st.top();
        
            st.pop();
        }
    
        reverse(res.begin(),res.end());
        
       
        return res;
    }
};