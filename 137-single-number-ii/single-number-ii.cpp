class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i += 3) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
            if (nums[i] != nums[i + 2]) {
                return nums[i];
            }
        }

        return nums[n - 1];
    }
};