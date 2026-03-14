class Solution {
public:
    int fib(int n) {
        double p = (sqrt(5)+1)/2;
        return round(pow(p,n)/sqrt(5));
    }
};