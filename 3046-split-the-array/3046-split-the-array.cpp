class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> counts;
        
        for (int num : nums) {
            counts[num]++;
            if (counts[num] > 2) {
                return false;
            }
        }
        
        return true;
    }
};