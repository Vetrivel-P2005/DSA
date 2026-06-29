class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int countEvens = 0;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                countEvens++;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i < countEvens) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }
        
        return nums;
    }
};