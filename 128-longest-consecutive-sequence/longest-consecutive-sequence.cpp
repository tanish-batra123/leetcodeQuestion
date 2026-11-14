class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.empty())return 0;
        
        sort(arr.begin(),arr.end());
        int cnt=1;
        int longest=1;
        for(int i=1;i<arr.size();i++){
             if(arr[i]==arr[i-1])continue;
            else if(arr[i]==arr[i-1]+1){
                cnt++;
                longest=max(longest ,cnt);
            }
           
            else cnt=1;
        }
        return longest;
    }
};