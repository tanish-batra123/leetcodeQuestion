class Solution {
public:
    vector<int> plusOne(vector<int>&arr) {
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==9){
                arr[i]=0;
            }else{
                arr[i]++;
                return arr;
            }
        }
        arr.resize(arr.size()+1);
        arr[0]=1;
        return arr;
    }
};