class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001] = {0};
        for (int x : arr) {
            freq[x + 1000]++;
        }
        bool seenFreq[1001] = {false};
        for (int f : freq) {
            if (f > 0) {
                if (seenFreq[f]) return false;
                seenFreq[f] = true;
            }
        }
        
        return true;
    }
};