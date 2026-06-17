class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i) {
            int target_index = (i + nums[i]) % n;
            
            if (target_index < 0) {
                target_index += n;
            }
            
            result[i] = nums[target_index];
        }
        
        return result;
    }
};