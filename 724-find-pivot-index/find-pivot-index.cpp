class Solution {
public:
    int pivotIndex(vector<int>&arr) {
        int totalSum=0;
        for(int ele:arr){
            totalSum+=ele;
        }
        int leftsum=0;
        for(int i=0;i<arr.size();i++){
             int rightsum=totalSum-leftsum-arr[i];
            if(leftsum==rightsum){
                return i;
            }
             leftsum+=arr[i];

        }

        return -1;
    }
};