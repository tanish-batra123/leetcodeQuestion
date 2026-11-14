class Solution {
public:
   int pivotidx(vector<int>&arr,int target){
    int low=0;
    int high=arr.size()-1;
    
    while(low<high){
        int mid=low+(high-low)/2;
        
        if(arr[mid] >= arr[high]){
           low=mid+1;
        }else{
            high=mid;
        }
    }

    return low;

   }
    int bs(int low,int high,vector<int>&arr,int target){
        
         while(low<=high){
            int mid=low + ((high-low)>>1);

            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid] > target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int pivot_idx=pivotidx(arr,target);

       int idx=bs(0,pivot_idx-1,arr,target);
       if(idx!=-1)return idx;
       idx=bs(pivot_idx,n-1,arr,target);
       return idx;
    }
};