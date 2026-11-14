class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low=0;
        int n=arr.size();
        int high=n-1;
        int first=-1;
        int last=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid] > target){
               high=mid-1;
            }
            else{
             low=mid+1;
            }
        }

        low=0;
        high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid] > target){
               high=mid-1;
            }
            else{
             low=mid+1;
            }
        }

        return {first,last};
    }
};