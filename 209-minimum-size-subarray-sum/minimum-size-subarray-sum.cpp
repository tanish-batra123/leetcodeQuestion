class Solution {
public:
    int minSubArrayLen(int target, vector<int>&arr) {
        int i=0;
        int j=0;
        int sum=0;
        int minlen=INT_MAX;

        while(j<arr.size()){
            sum+=arr[j];

            while(sum>=target){
              minlen=min(minlen,j-i+1);
              sum-=arr[i];
              i++;
            }

            j++;
        }
        return minlen==INT_MAX?0:minlen;
    }
};