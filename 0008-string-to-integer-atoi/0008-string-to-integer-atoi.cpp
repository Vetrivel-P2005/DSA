class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        long long res = 0;

        while (i < n && isspace(s[i])) i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

         while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -res < INT_MIN)
                return INT_MIN;

            i++;
        }
        
        return res*sign;
    }
};