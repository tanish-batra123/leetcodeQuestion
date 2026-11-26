class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        unordered_set<int>st;
        for(int ele:arr){
            if(ele>0)
            st.insert(ele);
        }

        for(int i=1;i<=arr.size()+1;i++){
            if(st.find(i)==st.end()){
              return i;
            }
        }

        return -1;
    }
};