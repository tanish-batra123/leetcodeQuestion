class Solution {
public:
    int maxProduct(vector<int>&arr) {
        int prod=1;
        int prod2=1;
        int maxprod=INT_MIN;
        

        for(int ele:arr){
            prod=prod*ele;
            maxprod=max(maxprod,prod);
            if(prod == 0){
                prod=1;
            }
        }
        for(int i=arr.size()-1;i>=0;i--){
           prod2*=arr[i];
            maxprod=max(maxprod,prod2);
           if(prod2==0)prod2=1;
          
        }
        return maxprod;
    }
};