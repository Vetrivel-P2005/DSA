class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> lookup; 
        for (int i = start; i < nums.size(); ++i) {
            if (lookup.count(nums[i])) continue; 

            lookup.insert(nums[i]);
            swap(nums[start], nums[i]);
            
            backtrack(start + 1, nums, result);
            
            swap(nums[start], nums[i]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};