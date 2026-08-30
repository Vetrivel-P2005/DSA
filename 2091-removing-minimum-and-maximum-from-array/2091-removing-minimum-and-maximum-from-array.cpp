class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
         int n = nums.size();
        if (n <= 2) return n; 

        int min_idx = 0;
        int max_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }

        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        int del_front = j + 1;

        int del_back = n - i;

        int del_both = (i + 1) + (n - j);

        return min({del_front, del_back, del_both});
    }
};