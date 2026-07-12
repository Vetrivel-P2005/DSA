class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        
        int operations = 0;
        while (n > 1) {
            if ((n & 1) == 0) {
                n >>= 1; 
            } else {
                if (n == 3 || (n & 2) == 0) {
                    n--;
                } else {
                    n++;
                }
            }
            operations++;
        }
        return operations;
    }
};