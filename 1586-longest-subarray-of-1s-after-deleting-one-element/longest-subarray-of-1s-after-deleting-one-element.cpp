class Solution {
public:
    int longestSubarray(vector<int>&arr) {
         int cntZero=0;
        int maxlen=0;
        int i=0;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==0)cntZero++;

            while(cntZero > 1){
                if(arr[i]==0)cntZero--;
                i++;
            }

            maxlen=max(maxlen,j-i+1);

        }
        return maxlen-1;
    }
};