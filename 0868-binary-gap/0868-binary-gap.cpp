class Solution {
public:
    int binaryGap(int n) {
        int max_gap = 0;
        int last_pos = -1;
        
        for (int i = 0; i < 31; ++i) {
            if ((n >> i) & 1) {
                if (last_pos != -1) {
                    max_gap = max(max_gap, i - last_pos);
                }
                last_pos = i;
            }
        }
        
        return max_gap;
    }
};