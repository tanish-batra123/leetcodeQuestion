class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low=1;
        int n=arr.size();
        int high=n-2;
        
        if(n==1)return 0;
        if(arr[0] > arr[1])return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        while(low<=high){
            int mid=low + ((high-low)>>1);

           if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
             return mid;
           }
            else if(arr[mid]>arr[mid-1]){
                 low=mid+1;
           }
           else{
             high=mid-1;
           }
        }
        return -1;
    }
};
//[1, 3, 5, 4, 7, 6, 8, 2]