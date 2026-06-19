class Solution {
private:
    vector<int> original;
    vector<int> current;
public:
    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }
    
    vector<int> reset() {
        current = original;
        return current;
    }
    
    vector<int> shuffle() {
        int n = current.size();
        for (int i = 0; i < n; ++i) {
            int randIdx = i + rand() % (n - i);
            swap(current[i], current[randIdx]);
        }
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */