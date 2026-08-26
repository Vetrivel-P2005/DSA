class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int left = 0, count1 = 0;
        
        int best_start = -1;
        int min_len = n + 1;

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                count1++;
            }

            while (count1 == k) {
                int current_len = right - left + 1;

                if (current_len < min_len) {
                    min_len = current_len;
                    best_start = left;
                } 
                else if (current_len == min_len) {
                    string_view current_sub(s.data() + left, current_len);
                    string_view best_sub(s.data() + best_start, min_len);
                    if (current_sub < best_sub) {
                        best_start = left;
                    }
                }

                if (s[left] == '1') {
                    count1--;
                }
                left++;
            }
        }

        return (best_start == -1) ? "" : s.substr(best_start, min_len);
    }
};