class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = piles[i];
        }

        for (int diff = 1; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                dp[i] = max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }
        return dp[0] >= 0;
    }
};