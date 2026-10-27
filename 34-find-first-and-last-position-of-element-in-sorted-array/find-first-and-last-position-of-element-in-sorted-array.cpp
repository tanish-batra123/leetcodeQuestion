class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        int start=-1;
        int end=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(arr[mid]==target){
                start=mid;
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
        high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(arr[mid]==target){
                end=mid;
               low=mid+1;
            }
            else if(arr[mid] > target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }

        return {start,end};
    }
};