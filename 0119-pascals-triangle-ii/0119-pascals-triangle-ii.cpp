class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> l;
        l.push_back((int)ans);
        for(int i=1;i<=rowIndex;i++){
            ans = ans*(rowIndex - i + 1) / i;
            l.push_back((int)ans);
        }
        return l;
    }
};