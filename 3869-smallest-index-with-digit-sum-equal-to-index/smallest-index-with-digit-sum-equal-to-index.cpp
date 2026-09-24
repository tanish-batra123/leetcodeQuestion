class Solution {
public:
int sumOfDigits(int n){
    int total=0;
    while(n){
        total+=n%10;
        n=n/10;
    }
    return total;

}
    int smallestIndex(vector<int>& arr) {
        int smallestIdx=INT_MAX;
        for(int i=0;i<arr.size();i++){
            int sod=sumOfDigits(arr[i]);
            if(i==sod){
             smallestIdx=min(smallestIdx,i);
            }

        }
        return smallestIdx==INT_MAX?-1:smallestIdx;
    }
};