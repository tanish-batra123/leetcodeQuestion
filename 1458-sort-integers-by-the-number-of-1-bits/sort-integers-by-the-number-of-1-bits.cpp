class Solution {
public:
    int setbits(int n) {
        int cnt = 0;
        while (n > 1) {
            if ((n & 1) == 1)
                cnt++;
            n = n >> 1;
        }
        if (n == 1)
            cnt++;
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[this](int a,int b){
           int sa=setbits(a);
           int sb=setbits(b);
           if(sa==sb)return a<b;
           return sa <sb;
        });
        return arr;
    }
};