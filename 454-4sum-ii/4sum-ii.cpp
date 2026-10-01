class Solution {
public:
    int fourSumCount(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3, vector<int>& arr4) {
        int cnt=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                int sum=arr1[i]+arr2[j];
                mpp[sum]++;
            }
        }
        for(int i=0;i<arr3.size();i++){
            for(int j=0;j<arr4.size();j++){
                int sum=arr3[i]+arr4[j];
                 if(mpp.find(-sum)!=mpp.end()){
                    cnt+=mpp[-sum];
                 }
            }
        }
        
        return cnt;
    }
};