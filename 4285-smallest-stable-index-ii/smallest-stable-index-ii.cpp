class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n=arr.size();
        int currMax = arr[0];
        vector<int> preMax(n);
        preMax[0] = currMax;
        int smallestIdx=INT_MAX;
        for (int i = 1; i < n; i++) {
            preMax[i] = max(arr[i], preMax[i - 1]);
        }
        
        vector<int> suffMin(n);
          suffMin[n-1]=arr[n-1];

        
        for(int i=n-2;i>=0;i--){
            suffMin[i]=min(arr[i],suffMin[i+1]);
        }

        for(int i=0;i<n;i++){
          if((preMax[i]-suffMin[i])<=k){
            smallestIdx=min(smallestIdx,i);
          }
        }
        return smallestIdx==INT_MAX?-1:smallestIdx;
    }
};