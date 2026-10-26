class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x=a|b;
        int z=x^c;
        int p=a&b;
        int q=z&p;
        return __popcount(z)+__popcount(q);
    }
};