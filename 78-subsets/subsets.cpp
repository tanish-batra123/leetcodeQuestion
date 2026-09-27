class Solution {
public:
void solve(  vector<int>&arr,  vector<int>&small, vector<vector<int>>&big,int idx){
    if(idx==arr.size()){
        big.push_back(small);
        return;
    }
    small.push_back(arr[idx]);
    solve(arr,small,big,idx+1);
    small.pop_back();
    solve(arr,small,big,idx+1);

}
    vector<vector<int>> subsets(vector<int>&arr) {
        vector<int>small={};
        vector<vector<int>>big;

        solve(arr,small,big,0);
        return big;
    }
};