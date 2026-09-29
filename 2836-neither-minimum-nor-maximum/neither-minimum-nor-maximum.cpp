class Solution {
public:
    int findNonMinOrMax(vector<int>& arr) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int val:arr){
            maxi=max(maxi,val);
            mini=min(mini,val);
        }

        int ans=-1;
        for(int val:arr){
            if(val!=maxi&&val!=mini){
                ans=val;
            }
        }
        return ans;
    }
};