class Solution {
public:
void solve(vector<int>&arr,vector<int>&small, vector<vector<int>>&big,int sum, int target,int idx){
    if(sum==target){
        big.push_back(small);
        return;
    }
    if(sum>target)return;

    for(int i=idx;i<arr.size();i++){
        small.push_back(arr[i]);
        solve(arr,small,big,sum+arr[i],target,i);
        small.pop_back();
      
    }

}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>small;
        vector<vector<int>>big;
        solve(arr,small,big,0,target,0);
        return big;
    }
};