class Solution {
public:
    int longestMonotonicSubarray(vector<int>&arr) {
        int longest1=1;
        int longest2=1;
        int longest=1;
         if (arr.empty()) return 0;

        for(int i=1;i<arr.size();i++){
            
            if(arr[i] > arr[i-1]){
                longest1++;
                longest2=1;
            }
            else if(arr[i] < arr[i-1]){
            longest2++;
            longest1=1;
            }
            else{
                longest1=1;
                longest2=1;
            }

            longest=max(longest,max(longest1,longest2));
        }
        return longest;
    }
};