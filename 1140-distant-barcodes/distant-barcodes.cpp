class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& arr) {
        unordered_map<int,int>mpp;
       
        vector<int>ans;
        int n=arr.size();
        for(int ele:arr){
            mpp[ele]++;
        }
         priority_queue<pair<int,int>> pq;
         for(auto it:mpp){
            pq.push({it.second,it.first});
         }
         vector<int> temp(n);
        int idx = 0;

       while(!pq.empty()){
        int freq=pq.top().first;
        int ele=pq.top().second;
        pq.pop();
        for(int i=0;i<freq;i++){
          temp[idx]=ele;
          idx+=2;
          if(idx>=n){
            idx=1;
          }
        }
       }

       
        
        return temp;

    }
};