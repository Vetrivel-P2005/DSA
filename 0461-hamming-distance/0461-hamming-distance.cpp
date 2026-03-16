class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int d = 0;
        while(n!=0){
            d+=n&1;
            n>>=1;
        }
        return d;
    }
};