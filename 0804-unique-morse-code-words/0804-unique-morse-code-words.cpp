class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
            ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
            ".--","-..-","-.--","--.."
        };
        
        unordered_set<string> transformations;
        
        for (const string& word : words) {
            string currentTransformation = "";
            for (char c : word) {
                currentTransformation += morse[c - 'a'];
            }
            transformations.insert(currentTransformation);
        }
        
        return transformations.size();
    }
};