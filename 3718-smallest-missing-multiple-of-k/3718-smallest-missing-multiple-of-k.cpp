class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int current = k;
        while (numSet.count(current)) {
            current += k;
        }
        
        return current;
    }
};