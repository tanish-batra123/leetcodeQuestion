class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        stack<int>st;
        vector<int>arr;

        while(i<pushed.size()&&j<popped.size()){
             st.push(pushed[i]);
            while(!st.empty()&&st.top()==popped[j]){
              arr.push_back(st.top());
              st.pop();
              j++;
            }
           
            i++;
            
        }
        if(arr!=popped)return false;
        return true;

    }
};