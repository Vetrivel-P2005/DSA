class Solution {
public:
    bool isNumber(string s) {
        std::regex pattern(R"(^[+-]?(\d+\.?\d*|\.\d+)([eE][+-]?\d+)?$)");
        return std::regex_match(s, pattern);
    }
};