class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        for (char c : s) {
            if (c == 'A') {
                absentCount++;
            }
        }
        
        return absentCount < 2 && s.find("LLL") == string::npos;
    }
};