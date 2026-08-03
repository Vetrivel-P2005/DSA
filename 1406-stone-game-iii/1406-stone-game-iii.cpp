class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; --i) {
            int current_take = 0;
            int max_advantage = -1e9; 

            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                current_take += stoneValue[i + k - 1];
                max_advantage = max(max_advantage, current_take - dp[(i + k) % 4]);
            }
            dp[i % 4] = max_advantage;
        }

        int alice_advantage = dp[0];

        if (alice_advantage > 0) {
            return "Alice";
        } else if (alice_advantage < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};