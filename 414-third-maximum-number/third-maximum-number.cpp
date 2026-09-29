class Solution {
public:
    int thirdMax(vector<int>& arr) {
        long long firstMax=LLONG_MIN;
        long long secondMax=LLONG_MIN;
        long long thirdMax=LLONG_MIN;

        for(int val:arr){
            if(val > firstMax){
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=val;
            }
            else if(val > secondMax && val!=firstMax){
                thirdMax=secondMax;
                secondMax=val;
                

            }
            else if(val >thirdMax && val!=firstMax && val!=secondMax){
                thirdMax=val;
            }
        }
        if(thirdMax==LLONG_MIN)return firstMax;

        return thirdMax;
    }
};