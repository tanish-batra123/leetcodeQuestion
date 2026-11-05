class Solution {
public:
    bool check(int possibleWeight, int days, vector<int>& arr) {

        int daysused = 1;
        int currload = 0;
        for (int weight : arr) {
           
            if (currload +weight > possibleWeight) {
                daysused++;
                currload = weight;
            }else{
                currload+=weight;
            }
        }

        return daysused<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        long long low = *max_element(arr.begin(),arr.end());
        long long high = 0;
        for (int ele : arr) {
            high += ele;
        }
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, days, arr)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return int(ans);
    }
};