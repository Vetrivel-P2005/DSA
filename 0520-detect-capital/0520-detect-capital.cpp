class Solution {
public:
    bool detectCapitalUse(string word) {
        int cc = 0;

        for(char c : word){
            if(isupper(c))cc++;
        }

        return cc == word.length() || cc == 0 || (cc == 1 && isupper(word[0]));
    }
};