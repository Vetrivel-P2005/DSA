class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& res, string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            res.push_back(current);
            return;
        }

        if (open < max) {
            backtrack(res, current + "(", open + 1, close, max);
        }
        
        if (close < open) {
            backtrack(res, current + ")", open, close + 1, max);
        }
    }
};