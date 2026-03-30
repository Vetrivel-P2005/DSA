class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rowMap = "12210111011122000010020202";
        vector<string> result;

        for (const string& word : words) {
            int firstCharRow = rowMap[tolower(word[0]) - 'a'];
            bool isValid = true;

            for (char c : word) {
                if (rowMap[tolower(c) - 'a'] != firstCharRow) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(word);
            }
        }
        return result;
    }
};