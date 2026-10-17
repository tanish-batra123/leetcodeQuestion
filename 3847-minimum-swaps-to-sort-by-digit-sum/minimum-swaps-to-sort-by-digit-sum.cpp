class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& arr) {
        int swaps = 0;
        vector<int> newarr = arr;

        sort(newarr.begin(), newarr.end(),
             [this](int a, int b) {
                 int dsa = digitSum(a);
                 int dsb = digitSum(b);
                 if(dsa==dsb)return a<b;
                 return dsa < dsb;
             });

            unordered_map<int, int>mpp;
        for (int i = 0; i < newarr.size(); i++) {
            mpp[arr[i]] = i;
        }

        for(int i=0;i<arr.size();i++){
            int currval=arr[i];
            int expectedval=newarr[i];
            if(currval==expectedval)continue;
            int idx=mpp[expectedval];

               arr[i]=expectedval;
               arr[idx]=currval;
                swaps++;
                mpp[expectedval]=i;
                mpp[currval]=idx;
            
        }

        return swaps;
    }
};