class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i=0,j=0;
        int zero=0;
        int maxOnes=INT_MIN;
        while(j<arr.size()){
            if(arr[j]==0)zero++;
            while(zero>k){
                if(arr[i]==0)zero--;
                i++;
            }
            maxOnes=max(maxOnes,j-i+1);
            j++;
        }
        return maxOnes;
    }
};