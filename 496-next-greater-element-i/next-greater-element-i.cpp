class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        stack<int>st;
        vector<int>nge(arr2.size());
        for(int i=0;i<arr2.size();i++){
            while(!st.empty()&&arr2[st.top()]<arr2[i])
            {
              nge[st.top()]=arr2[i];
              st.pop();
            }
            st.push(i);
            
        }

        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
        vector<int>ans;

        for(int ele:arr1){
            for(int j=0;j<arr2.size();j++){
                if(arr2[j]==ele){
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;

    }
};