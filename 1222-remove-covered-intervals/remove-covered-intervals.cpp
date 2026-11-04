class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(),
     [](vector<int>& a, vector<int>& b) {
         if (a[0] == b[0]) return a[1] > b[1];
         return a[0] < b[0];
     });
        vector<vector<int>> temp;
        int cnt = 0;

        for (auto interval : intervals) {
            if (temp.empty()) {
                temp.push_back(interval);
            }
            else if (temp.back()[0] <= interval[0] &&
                     temp.back()[1] >= interval[1]) {
                cnt++;
            }
            else {
                temp.push_back(interval);
            }
        }

        return intervals.size() - cnt;
    }
};