class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>&arr) {
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
          while(!st.empty()&&arr[i]>arr[st.top()]){
            int poppedIdx=st.top();
            st.pop();
            ans[poppedIdx]++;
          }
          if(!st.empty()){
            ans[st.top()]++;
          }
           st.push(i);
          
        }
        return ans;
        
    }
};