class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        
        unordered_set<int> existing(nums.begin(), nums.end());
        
        vector<int> missing;
        
        for (int i = min_val + 1; i < max_val; ++i) {
            if (existing.find(i) == existing.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};