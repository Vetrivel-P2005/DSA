class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        
        string result = "1";
        
        for (int i = 1; i < n; ++i) {
            string next_round = "";
            int len = result.length();
            
            for (int j = 0; j < len; ) {
                int count = 1;
                while (j + count < len && result[j] == result[j + count]) {
                    count++;
                }
                
                next_round += to_string(count) + result[j];
                
                j += count;
            }
            result = next_round;
        }
        
        return result;
    }
};