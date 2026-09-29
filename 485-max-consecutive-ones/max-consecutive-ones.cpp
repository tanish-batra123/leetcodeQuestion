class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                count++;
                maxCount=max(count,maxCount);
            }else{
                count=0;
            }
        }
        return maxCount;
    }
};