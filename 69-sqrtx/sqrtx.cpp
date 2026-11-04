class Solution {
public:
    int mySqrt(int x) {
        long long low=1;
       long long high=x;
        int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;

            if(mid*mid <= x){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};