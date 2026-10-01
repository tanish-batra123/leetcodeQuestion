class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<vector<int>>ans;
        set<pair<int,pair<int,pair<int,int>>>>st;
        for (int i = 0; i < n-3; i++) {
            for (int j = i + 1; j < n-2; j++) {
                int p = j + 1;
                int q = n - 1;

                while (p < q) {
                    long long sum = (long long)arr[i] + arr[j] + arr[p] + arr[q];
                    if (sum == target) {
                        st.insert({arr[i], {arr[j], {arr[p], arr[q]}}});
                        p++;
                        q--;
                    }

                    else if(sum > target){
                        q--;
                    }else{
                        p++;
                    }
                }
            }
        }

        for(auto it:st){
            ans.push_back({it.first,it.second.first,it.second.second.first,it.second.second.second});
        }
        return ans;
    }
};