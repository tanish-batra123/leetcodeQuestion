class Solution {
public:
    void moveZeroes(vector<int>&arr) {
        int i=0;
        int j=0;
        while(j<arr.size()){
            if(arr[j]!=0){
              swap(arr[i],arr[j]);
              i++;
            }
            j++;
        }
    }
};