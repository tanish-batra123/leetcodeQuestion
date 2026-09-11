class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
         stack<int>st;
          int n=arr.size();
        vector<int>nge(n,-1);
       
        for(int i=0;i<2*n;i++){
            int curr=arr[i%n];
            while(!st.empty()&&arr[st.top()]<curr)
            {
              nge[st.top()]=curr;
              st.pop();
            }
            if(i<n)st.push(i);
           

        }
        return nge;
    }
};