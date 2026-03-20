class Solution {
public:
    int longestPalindrome(string s) {
        int counts[128] = {0};
        for (char c : s) counts[(int)c]++;

        int res = 0;
        for (int count : counts) {
            res += (count / 2) * 2;
        }

        return (res < s.length()) ? res + 1 : res;
    }
};