class Solution {
public:
int increasing(vector<int>&arr){
    int longest=1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int length=0;
        for(int j=i+1;j<n;j++){
            if(j-1>=0 && arr[j] > arr[j-1]){
                 length=j-i+1;
                 longest=max(longest,length);
            }else{
                break;
            }
               
        }
    }
    return longest;
}

int decreasing(vector<int>&arr){
    int longest=1;
     int n=arr.size();
    for(int i=0;i<n;i++){
        int length=0;
        for(int j=i+1;j<n;j++){
            if(j-1>=0 && arr[j] < arr[j-1]){
                 length=j-i+1;
                 longest=max(longest,length);
            }else{
                break;
            }
               
        }
    }
    return longest;

}
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(increasing(nums),decreasing(nums));
    }
};