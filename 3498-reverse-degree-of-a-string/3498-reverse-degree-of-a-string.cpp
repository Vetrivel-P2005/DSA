class Solution {
public:
    int reverseDegree(string s) {
        int total_sum = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int rev_alphabet_pos = 26 - (s[i] - 'a');
            
            int string_pos = i + 1;
            
            total_sum += rev_alphabet_pos * string_pos;
        }
        
        return total_sum;
    }
};