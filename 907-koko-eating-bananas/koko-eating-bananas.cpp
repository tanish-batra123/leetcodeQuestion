class Solution {
public:
bool isEat(int k,vector<int>&arr,int hour){
    long long possible=0;
    for(int ele:arr){
          possible += (ele + k - 1) / k;
    }
    return possible<=hour;
}
    int minEatingSpeed(vector<int>&arr, int h) {
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;

            if(isEat(mid,arr,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return int(ans);
    }
};