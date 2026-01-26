class Solution {
public:
    string convert(string s, int numRows) {
         if (numRows <= 1 || s.length() <= numRows) return s;

        string res = "";
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                res += s[j + i];
                
                int secondCharIdx = j + cycleLen - i;
                if (i != 0 && i != numRows - 1 && secondCharIdx < n) {
                    res += s[secondCharIdx];
                }
            }
        }
        return res;
    }
};