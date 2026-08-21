class Solution {
private:
    long long countMultiples(const std::vector<int>& coins, int n, long long mid) {
        long long total_count = 0;
        int total_subsets = (1 << n);
        
        for (int mask = 1; mask < total_subsets; ++mask) {
            long long current_lcm = 1;
            int element_count = 0;
            bool overflow = false;
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    element_count++;
                    long long g = std::gcd(current_lcm, (long long)coins[i]);
                    
                    if (current_lcm > mid / (coins[i] / g)) {
                        overflow = true;
                        break;
                    }
                    current_lcm = (current_lcm / g) * coins[i];
                }
            }
            
            if (overflow) continue;
            
            long long multiples = mid / current_lcm;
            
            if (element_count % 2 == 1) {
                total_count += multiples;
            } else {
                total_count -= multiples;
            }
        }
        
        return total_count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        long long min_coin = *std::min_element(coins.begin(), coins.end());
        
        long long low = 1;
        long long high = min_coin * k;
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countMultiples(coins, n, mid) >= k) {
                ans = mid;     
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        
        return ans;
    }
};