class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int n = num;
        string hexChars = "0123456789abcdef";
        string result = "";
        
        while (n > 0) {
            int lastFourBits = n & 0xf;
            result = hexChars[lastFourBits] + result;
            
            n >>= 4;
        }
        
        return result;
    }
};