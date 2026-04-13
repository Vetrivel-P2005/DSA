class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int left = 0;
        int right = n;
        vector<int> result;

        for (char c : s) {
            if (c == 'I') {
                result.push_back(left++);
            } else {
                result.push_back(right--);
            }
        }

        result.push_back(left);

        return result;
    }
};