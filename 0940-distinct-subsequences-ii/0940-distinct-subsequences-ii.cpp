class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long> last(26, 0); 
        long current_total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long new_subseqs = (current_total + 1) % MOD;
            
            current_total = (current_total + new_subseqs - last[idx] + MOD) % MOD;
            
            last[idx] = new_subseqs;
        }

        return current_total;

    }
};