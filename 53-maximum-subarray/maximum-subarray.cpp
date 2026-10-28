class Solution {
public:
    int maxSubArray(vector<int>&arr) {
        int sum=0;
        int maxsum=INT_MIN;
        for(int ele:arr){
            sum+=ele;
            maxsum=max(maxsum,sum);
            if(sum < 0){
                sum=0;
            }
        }
        return maxsum;
    }
};