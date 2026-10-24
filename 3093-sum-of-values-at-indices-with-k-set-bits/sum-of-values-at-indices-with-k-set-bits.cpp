class Solution {
public:
int cntOnes(int n){
     int cnt=0;
        while(n>1){
            if((n & 1)==1)cnt++; 
            n=n/2;
        }
        if(n==1)cnt++;

        return cnt;
}
    int sumIndicesWithKSetBits(vector<int>&arr, int k) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            
            if(cntOnes(i)==k){
                sum+=arr[i];
            }
        }
        return sum;
    }
};