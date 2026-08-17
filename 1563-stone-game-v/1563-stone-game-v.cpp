class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n <= 1) return 0;

        vector<int> prefixSums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                for (int k = i; k < j; ++k) {
                    int leftSum = prefixSums[k + 1] - prefixSums[i];
                    int rightSum = prefixSums[j + 1] - prefixSums[k + 1];

                    if (leftSum < rightSum) {
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        dp[i][j] = max(dp[i][j], rightSum + dp[k + 1][j]);
                    } else {
                        dp[i][j] = max({dp[i][j], leftSum + dp[i][k], rightSum + dp[k + 1][j]});
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};