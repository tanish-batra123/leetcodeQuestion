class Solution {
public:
    vector<int>givePrime(int n){
         vector<int>primes;
        vector<int>isprime(n+1,true);
        isprime[0]=false;
        isprime[1]=false;

        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(isprime[i]){
             primes.push_back(i);
            }
        }
        return primes;

    }

    int bs(vector<int>arr,int target){
        int low=0;
        int high=arr.size()-1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<target){
             ans=arr[mid];
             low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    bool primeSubOperation(vector<int>& arr) {
        vector<int>primes=givePrime(1000);
        
        for(int i=0;i<arr.size();i++){
             int target;
             if(i==0)  target=arr[i];
             else target=arr[i]-arr[i-1];

             int prime = bs(primes, target);

            arr[i] -= prime;
            if(i>0 && arr[i] <=arr[i-1])return false;
            
        }
        return true;

    }
};