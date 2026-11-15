class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size(),0);
        
        for(int i=0;i<arr.size();i++){
            
            while(!st.empty()&&arr[i] > arr[st.top()]){
                int idx=st.top();
                ans[idx]=i-idx;
                st.pop();
            }
            st.push(i);
            
        }
        return ans;
    }
};