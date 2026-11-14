class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&arr, int k) {
        vector<int>ans;
        int i=0;
        int j=0;
        priority_queue<pair<int,int>>pq;
        while( j< arr.size()){
         pq.push({arr[j],j});
        
         if(j-i+1>k){
            i++;
         }
         while(!pq.empty() && i >  pq.top().second){
            pq.pop();
         }
         if(j-i+1==k){
            auto[ele,idx]=pq.top();
            ans.push_back(arr[idx]);
         }
         j++;

        }
        return ans;
    }
};