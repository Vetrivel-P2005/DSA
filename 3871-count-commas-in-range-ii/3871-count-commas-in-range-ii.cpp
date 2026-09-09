class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        
        long long thresholds[] = {
            1000LL, 
            1000000LL, 
            1000000000LL, 
            1000000000000LL, 
            1000000000000000LL, 
            1000000000000000000LL 
        };
        
        for (int i = 0; i < 5; ++i) {
            if (n >= thresholds[i]) {
                long long rangeEnd = min(n, thresholds[i + 1] - 1);
                long long countOfNumbers = rangeEnd - thresholds[i] + 1;
                totalCommas += countOfNumbers * (i + 1);
            } else {
                break; 
            }
        }
        
        return totalCommas;
    }
};