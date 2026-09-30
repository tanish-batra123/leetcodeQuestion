class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i=0;
        int j=arr.size()-1;
        vector<int>ans;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==target){
              ans.push_back(i+1);
              ans.push_back(j+1);
              i++;
              j--;
            }
            if(sum>target){
                j--;
            }else i++;
        }
        return ans;
    }
};