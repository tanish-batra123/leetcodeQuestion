class Solution {
public:
    int searchInsert(vector<int>arr, int target) {

        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int ans=0;

            if(arr[mid]==target){
                return mid;
            }else if(arr[mid] > target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return low;
        
    }
};