class Solution {
public:
int calcOnes(int n){
    int cnt=0;
        while(n>1){
            if((n & 1)==1)cnt++; 
            n=n/2;
        }
        if(n==1)cnt++;
        return cnt;
}
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
         
         for(int i=0;i<=n;i++){
            ans[i]=calcOnes(i);
         }
         return ans;
    }
};