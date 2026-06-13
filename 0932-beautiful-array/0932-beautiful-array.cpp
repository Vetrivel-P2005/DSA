class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};
        
        while (res.size() < n) {
            vector<int> next_res;
            
            for (int x : res) {
                if (2 * x - 1 <= n) {
                    next_res.push_back(2 * x - 1);
                }
            }
            
            for (int x : res) {
                if (2 * x <= n) {
                    next_res.push_back(2 * x);
                }
            }
            
            res = next_res;
        }
        
        return res;
    }
};