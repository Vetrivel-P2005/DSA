class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, 1e9));
        dp[0][0] = 0;

        for (int x : nums) {
            vector<vector<int>> next_dp(op1 + 1, vector<int>(op2 + 1, 1e9));
            
            for (int j = 0; j <= op1; ++j) {
                for (int l = 0; l <= op2; ++l) {
                    if (dp[j][l] == 1e9) continue;

                    next_dp[j][l] = min(next_dp[j][l], dp[j][l] + x);

                    if (j + 1 <= op1) {
                        int val = (x + 1) / 2;
                        next_dp[j + 1][l] = min(next_dp[j + 1][l], dp[j][l] + val);
                    }

                    if (l + 1 <= op2 && x >= k) {
                        int val = x - k;
                        next_dp[j][l + 1] = min(next_dp[j][l + 1], dp[j][l] + val);
                    }

                    if (j + 1 <= op1 && l + 1 <= op2) {
                        int min_val = 1e9;
                        
                        int op1_first = (x + 1) / 2;
                        if (op1_first >= k) {
                            min_val = min(min_val, op1_first - k);
                        }
                        
                        if (x >= k) {
                            int op2_first = x - k;
                            min_val = min(min_val, (op2_first + 1) / 2);
                        }
                        
                        if (min_val != 1e9) {
                            next_dp[j + 1][l + 1] = min(next_dp[j + 1][l + 1], dp[j][l] + min_val);
                        }
                    }
                }
            }
            dp = move(next_dp);
        }

        int min_sum = 1e9;
        for (int j = 0; j <= op1; ++j) {
            for (int l = 0; l <= op2; ++l) {
                min_sum = min(min_sum, dp[j][l]);
            }
        }

        return min_sum;
    }
};