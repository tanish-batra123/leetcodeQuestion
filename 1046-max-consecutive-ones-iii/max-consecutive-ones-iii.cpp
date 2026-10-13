class Solution {
public:
    int longestOnes(vector<int>&arr, int k) {
        int cntZero=0;
        int maxlen=0;
        int i=0;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==0)cntZero++;

            while(cntZero > k){
                if(arr[i]==0)cntZero--;
                i++;
            }

            maxlen=max(maxlen,j-i+1);

        }
        return maxlen;
    }
};