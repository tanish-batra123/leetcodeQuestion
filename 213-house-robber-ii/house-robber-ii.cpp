class Solution {
public:
int solve(vector<int>&arr) {
		
		int next1=0;
       int next2=0;
       int n=arr.size();
       
		
		for (int i = n - 1; i >= 0; i--) {
			int include = arr[i]+next2;
			int exclude = next1;
			int curr = max(include, exclude);
			next2 = next1;
            next1 = curr;
		}
		return next1;
		
	}
    int rob(vector<int>& nums) {
        vector<int>arr1;
         vector<int>arr2;
         int n=nums.size();
         
         for(int i=0;i<n;i++){
            if(i!=n-1){
             arr2.push_back(nums[i]);
            }
             if(i!=0){
              arr1.push_back(nums[i]);
            }
         }
        if(n==1)return nums[0];
        int ans1=solve(arr1);
        int ans2=solve(arr2);
        return max(ans1,ans2);
    }
};