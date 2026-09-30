class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int maxA=0;
        while(i<j){
             int area=(j-i)*(min(arr[i],arr[j]));
                maxA=max(maxA,area);
            if(arr[i]>=arr[j]){
                j--;
            }
            else  i++;
           
        }
        return maxA;
    }
};