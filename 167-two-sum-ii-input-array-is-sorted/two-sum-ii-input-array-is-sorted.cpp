class Solution {
public:
    vector<int> twoSum(vector<int>&arr, int target) {
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==target){
                return {i+1,j+1};
            }
            else if(sum < target){
                i++;
            }else{
                j--;
            }
        }
        return {};

    }
};