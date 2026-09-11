class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int availableCounts[10] = {0};
        for (int d : digits) {
            availableCounts[d]++;
        }
        
        int validCount = 0;
        
        for (int i = 100; i <= 998; i += 2) {
            int currentCounts[10] = {0};
            int temp = i;
            
            while (temp > 0) {
                currentCounts[temp % 10]++;
                temp /= 10;
            }
            
            bool isPossible = true;
            for (int d = 0; d < 10; d++) {
                if (currentCounts[d] > availableCounts[d]) {
                    isPossible = false;
                    break;
                }
            }
            
            if (isPossible) {
                validCount++;
            }
        }
        
        return validCount;
    }
};