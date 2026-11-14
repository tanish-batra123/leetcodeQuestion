class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            if(mpp.find(target-arr[i])!=mpp.end()){
                return {i,mpp[target-arr[i]]};
            }
            mpp[arr[i]]=i;
        }
        return {};
    }
};