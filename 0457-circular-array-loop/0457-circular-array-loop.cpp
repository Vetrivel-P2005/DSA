class Solution {
public:
    int getNext(vector<int>& nums, int i, int n) {
        int next_idx = ((i + nums[i]) % n + n) % n;
        return next_idx;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return false;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;

            int slow = i;
            int fast = i;

            bool isForward = nums[i] > 0;

            while (true) {
                int next_slow = getNext(nums, slow, n);
                if ((nums[next_slow] > 0) != isForward || nums[next_slow] == 0) break;
                slow = next_slow;

                int next_fast1 = getNext(nums, fast, n);
                if ((nums[next_fast1] > 0) != isForward || nums[next_fast1] == 0) break;
                
                int next_fast2 = getNext(nums, next_fast1, n);
                if ((nums[next_fast2] > 0) != isForward || nums[next_fast2] == 0) break;
                fast = next_fast2;

                if (slow == fast) {
                    if (slow == getNext(nums, slow, n)) {
                        break; 
                    }
                    return true;
                }
            }

            slow = i;
            while (true) {
                int next_node = getNext(nums, slow, n);
                if ((nums[slow] > 0) != isForward || nums[slow] == 0) break;
                nums[slow] = 0;
                slow = next_node;
            }
        }

        return false;
    }
};