class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
         vector<int>ans(n,-1);
         stack<int>st;
         for(int i=0;i<n;i++){
            arr.push_back(arr[i]);
         }
         for(int i=0;i<arr.size();i++){
            
            while(!st.empty()&&arr[i] > arr[st.top()]){
                int idx=st.top();
                ans[idx%n]=arr[i];
                st.pop();
            }
            st.push(i);
            
        }

        return ans;

    }
};