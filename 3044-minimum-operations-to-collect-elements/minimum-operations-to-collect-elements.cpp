class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        int n=arr.size();
        int mark=0;
        int cnt=0;
        for(int ele:arr){
            mpp[ele]=0;
        }
        for(int i=n-1;i>=0;i--){
         if(arr[i]<=k&&mpp[arr[i]]==0){
            mpp[arr[i]]=1;
            mark++;
             
         }
         if(mark==k){
            cnt++;
            break;
         }
         cnt++;
        }
        return cnt;

       

    }
};