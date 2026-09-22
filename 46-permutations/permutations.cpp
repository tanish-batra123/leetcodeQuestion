class Solution {
public:

void helper(vector<int>&arr,vector<int>&small, vector<vector<int>>&big,vector<int>&visited){
    if(arr.size()==small.size()){
        big.push_back(small);
        return;
    }
    
    for(int i=0;i<arr.size();i++){
     
        if(!visited[i]){
         small.push_back(arr[i]);
         visited[i]=true;
         helper(arr,small,big,visited);
          small.pop_back();
          visited[i]=false;
        }
       

    }

}
    vector<vector<int>> permute(vector<int>&arr) {
        vector<int>small;
       vector<vector<int>>big;
       vector<int>visited(arr.size(),false);
       helper(arr,small,big,visited);
       return big;

    }
};