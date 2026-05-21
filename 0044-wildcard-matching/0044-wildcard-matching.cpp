class Solution {
public:
    bool isMatch(string s, string p) {
        int s_idx = 0, p_idx = 0;
        int star_idx = -1;
        int s_backtrack = -1;
        int s_len = s.length();
        int p_len = p.length();

        while (s_idx < s_len) {
            if (p_idx < p_len && (p[p_idx] == s[s_idx] || p[p_idx] == '?')) {
                s_idx++;
                p_idx++;
            }
            else if (p_idx < p_len && p[p_idx] == '*') {
                star_idx = p_idx;
                s_backtrack = s_idx;
                p_idx++; 
            }
            else if (star_idx != -1) {
                s_backtrack++; 
                s_idx = s_backtrack;
                p_idx = star_idx + 1; 
            }
            else {
                return false;
            }
        }

        while (p_idx < p_len && p[p_idx] == '*') {
            p_idx++;
        }

        return p_idx == p_len;
    }
};