class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        vector<int> max_pref(n);
        max_pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            max_pref[i] = max(max_pref[i - 1], nums[i]);
        }

        vector<int> min_suff(n);
        min_suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            min_suff[i] = min(min_suff[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (max_pref[i] - min_suff[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};