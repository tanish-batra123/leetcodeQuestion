class Solution {
public:
    double findMaxAverage(vector<int>&arr, int k) {
        int i=0;
        int j=0;
        double sum=0;
       
        double maxAvg=INT_MIN;

        while(j<arr.size()){
          sum+=arr[j];

          if(j-i+1==k){
            double avg=sum/k;
            maxAvg=max(maxAvg,avg);
            sum-=arr[i];
            i++;
          }
          j++;

        }

        return maxAvg;
    }
};