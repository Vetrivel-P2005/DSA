class Solution {
public:
    vector<int> grayCode(int n) {
        int totalElements = 1 << n;
        vector<int> result;
        result.reserve(totalElements);
        
        for (int i = 0; i < totalElements; ++i) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};