class Solution {
public:
    int countGoodRotations(vector<int>& arr) {
        long long total=0;
        int cnt=0;
        int n=arr.size();
        vector<int>newarr(arr.begin(),arr.end());
        for(int ele:arr){
            total+=ele;
        }
        long long left=0;
        
        for(int i=0;i<arr.size();i++){
            newarr.push_back(arr[i]);
        }
        int k=n/2;
        for(int i=0;i<k;i++){
            left+=newarr[i];
        }

        for(int i=0;i<n;i++){
            long long right=total-left;
            if(left > right)cnt++;
            left=left-newarr[i];
            left=left+newarr[i+(n/2)];
        }

        return cnt;
    }
};