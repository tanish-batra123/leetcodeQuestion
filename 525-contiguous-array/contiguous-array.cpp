class Solution {
public:
    int findMaxLength(vector<int>&arr) {
        unordered_map<int,int>mpp;
        int sum=0;
        int maxLength=0;
        mpp[0]=-1;
    
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)sum+=1;
            else sum+=-1;
            
            if(mpp.find(sum)!=mpp.end()){
                maxLength=max(maxLength,abs(i-mpp[sum]));
            }
           else  mpp[sum]=i;
        }
        
        return maxLength;
    }
};