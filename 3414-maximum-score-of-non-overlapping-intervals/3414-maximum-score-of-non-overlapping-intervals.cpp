class Solution {
    struct Interval {
        int l, r, weight, id;
        bool operator<(const Interval& other) const {
            return l < other.l;
        }
    };

    vector<int> insertSorted(const vector<int>& vec, int val) {
        vector<int> res = vec;
        res.insert(lower_bound(res.begin(), res.end(), val), val);
        return res;
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        sort(items.begin(), items.end());

        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0, {}}));

        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = items[i].l;
        }

        for (int i = n - 1; i >= 0; --i) {
            int next_idx = upper_bound(starts.begin() + i, starts.end(), items[i].r) - starts.begin();

            for (int k = 1; k <= 4; ++k) {
                auto best = dp[i + 1][k];

                long long take_weight = items[i].weight + dp[next_idx][k - 1].first;
                vector<int> take_indices = insertSorted(dp[next_idx][k - 1].second, items[i].id);

                if (take_weight > best.first || (take_weight == best.first && (best.second.empty() || take_indices < best.second))) {
                    best = {take_weight, take_indices};
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].second;
    }
};