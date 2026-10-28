class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int total=0;
        int sum1=0;
        int sum2=0;
        int maxsum=INT_MIN;
        int minsum=INT_MAX;

        for(int ele:arr){
            total+=ele;

            sum1+=ele;
            sum2+=ele;
            maxsum=max(maxsum,sum1);
            minsum=min(minsum,sum2);
            if(sum1<0){
                sum1=0;
            }
            if(sum2 > 0){
                sum2=0;
            }


        }
        int ans=total-minsum;
        if(maxsum < 0)return maxsum;
        return max(maxsum,ans);
    }
};

