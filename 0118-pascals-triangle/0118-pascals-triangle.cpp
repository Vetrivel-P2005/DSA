class Solution {
public:
    vector<int> generateRow(int n) {
        long long ans = 1;
        vector<int> a;
        a.push_back(1);
        for(int col = 1;col<n;col++){
            ans *= (n-col);
            ans/=col;
            a.push_back(ans);
        }
        return a;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};