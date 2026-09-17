class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        
        int l = 0;
        int window_sum = 0;
        int ans = INT_MAX;
        int current_min_len = INT_MAX;

        for (int r = 0; r < n; ++r) {
            window_sum += arr[r];

            while (window_sum > target) {
                window_sum -= arr[l];
                l++;
            }

            if (window_sum == target) {
                int current_len = r - l + 1;
                
                if (l > 0 && min_len[l - 1] != INT_MAX) {
                    ans = min(ans, current_len + min_len[l - 1]);
                }
                
                current_min_len = min(current_min_len, current_len);
            }
            
            min_len[r] = current_min_len;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};