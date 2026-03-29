class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first, last;
        int degree = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (first.find(x) == first.end()) {
                first[x] = i;
            }
            last[x] = i;
            count[x]++;
            degree = max(degree, count[x]);
        }
        
        int minLength = nums.size();
        for (auto const& [val, freq] : count) {
            if (freq == degree) {
                minLength = min(minLength, last[val] - first[val] + 1);
            }
        }
        
        return minLength;
    }
};