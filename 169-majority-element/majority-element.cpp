class Solution {
public:
    int majorityElement(vector<int>&arr) {
        int king=arr[0];
        int cnt=1;

        for(int i=1;i<arr.size();i++){
            if(arr[i]==king)cnt++;
            else{
                cnt--;
                if(cnt==0){
                    king=arr[i];
                    cnt=1;
                }
            }
        }
        return king;
    }
};