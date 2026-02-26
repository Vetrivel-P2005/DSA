class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> m(n+1);
        m[0]=0;

        for(int i=1;i<=n;i++)
            m[i] = m[i/2] + i%2;

        return m;
    }
};