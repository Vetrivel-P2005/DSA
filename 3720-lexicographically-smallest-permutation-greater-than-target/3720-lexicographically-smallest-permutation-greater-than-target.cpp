class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int best_i = -1;
        vector<int> temp_count = count;
        
        for (int i = 0; i < n; ++i) {
           
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (temp_count[c] > 0) {
                    best_i = i;
                    break;
                }
            }
            if (temp_count[target[i] - 'a'] > 0) {
                temp_count[target[i] - 'a']--;
            } else {
                break; 
            }
        }
        
        if (best_i == -1) {
            return "";
        }
        
        string result = "";
        for (int i = 0; i < best_i; ++i) {
            result += target[i];
            count[target[i] - 'a']--;
        }
        
        for (int c = target[best_i] - 'a' + 1; c < 26; ++c) {
            if (count[c] > 0) {
                result += (char)('a' + c);
                count[c]--;
                break;
            }
        }
        
        for (int c = 0; c < 26; ++c) {
            while (count[c] > 0) {
                result += (char)('a' + c);
                count[c]--;
            }
        }
        
        return result;
    }
};