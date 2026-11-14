class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int ele:arr){
            mpp[ele]++;
        }
        for(auto it:mpp){
            if(it.second>=2)return true;
        }
        return false;
    }
};