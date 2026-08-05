class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxlen = 0;
        int left = 0;

        for(int right = 0;right<s.size();right++){
            char ch = s[right];

            if(mp.find(ch)!=mp.end() && mp[ch]>=left){
                left = mp[ch] + 1;
            }

            mp[ch] = right;
            maxlen = max(maxlen,right-left+1);
        }

        return maxlen;
    }
};