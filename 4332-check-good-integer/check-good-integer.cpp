class Solution {
public:
int digitSum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int squareSum(int n){
    int sum=0;
    while(n){
        int lastDigit=n%10;
        sum+=lastDigit*lastDigit;
        n=n/10;
    }
    return sum;
}
    bool checkGoodInteger(int n) {
        int x=digitSum(n);
        int y=squareSum(n);
        if(y-x>=50)return true;
        return false;

    }
};