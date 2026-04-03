class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.length(); i++) {
            last_occurrence[s[i]] = i;
        }
        string result = "";
        unordered_set<char> visited;
         for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (visited.find(c) != visited.end()) continue;
            while (!result.empty() && c < result.back() && i < last_occurrence[result.back()]) {
                visited.erase(result.back());
                result.pop_back();
            }
            result.push_back(c);
            visited.insert(c);
        }

        return result;
    }
};