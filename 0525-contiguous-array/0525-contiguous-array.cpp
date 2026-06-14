class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumMap;
        
        sumMap[0] = -1;
        
        int maxLen = 0;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += (nums[i] == 0) ? -1 : 1;
            
            if (sumMap.find(currentSum) != sumMap.end()) {
                maxLen = max(maxLen, i - sumMap[currentSum]);
            } else {
                sumMap[currentSum] = i;
            }
        }
        
        return maxLen;
    }
};