class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        int d = (dividend < 0) ? dividend : -dividend;
        int s = (divisor < 0) ? divisor : -divisor;

        int quotient = 0;
        
        while (d <= s) {
            int currentCount = -1;
            int currentDivisor = s;
            
            while (currentDivisor >= -1073741824 && d <= (currentDivisor << 1)) {
                currentDivisor <<= 1;
                currentCount <<= 1;
            }

            d -= currentDivisor;
            quotient += currentCount;
        }

        if (!isNegative) {
            if (quotient == INT_MIN) return INT_MAX;
            return -quotient;
        }
        
        return quotient;
    }
};