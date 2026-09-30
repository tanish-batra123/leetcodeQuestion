class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set<pair<int,pair<int,int>>>s;
        for (int p = 0; p < arr.size(); p++) {
            int i = p + 1;
            int j = arr.size() - 1;

            while (i < j) {
                int sum = arr[p] + arr[i] + arr[j];

                if (sum == 0) {
                    s.insert({arr[p],{arr[i],arr[j]}});
                    i++;
                    j--;
                } else if (sum > 0) {
                    j--;
                } else {
                    i++;
                }
            }
        }

        for(auto it:s){
            ans.push_back({it.first,it.second.first,it.second.second});
        }

        return ans;
    }
};