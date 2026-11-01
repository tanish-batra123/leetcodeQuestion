class Solution {
public:
    int minMergedInteger(vector<int>&arr) {
        int i=0;
        int ans=INT_MAX;
        while(i<arr.size()){
            string temp=to_string(arr[i])+to_string(arr[i+1]);
            ans=min(ans,stoi(temp));
            i=i+2;
        }
        return ans;
    }
};