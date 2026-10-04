class Solution {
public:
int findRange(int n){
    int maxi=INT_MIN;
    int mini=INT_MAX;

    while(n){
        int last=n%10;
        maxi=max(maxi,last);
        mini=min(mini,last);
        n=n/10;
    }
    return maxi-mini;
}
    int maxDigitRange(vector<int>&arr) {
        int maxrange=0;
        int sum=0;
         for(int num:arr){
            int range=findRange(num);
            if(range >= maxrange){
                maxrange=range;
            }
         }
         for(int num:arr){
            int range=findRange(num);
            if(range==maxrange)sum+=num;
         }
         return sum;
    }
};