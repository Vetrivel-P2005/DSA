class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp;

        for(const auto& ele : reservedSeats){
            int row = ele[0];
            int col = ele[1];

            if(col>=2 && col<=9){
                mp[row] |= (1<<(col-2));
            }
        }

        int mf = (n-mp.size())*2;

        int left = 15;
        int mid = 60;
        int right = 240;

        for(const auto& [ro,m] : mp){
            bool l = (left & m) == 0;
            bool r = (right & m) == 0;
            bool mi = (mid & m) == 0;

            if(l && r) mf+=2;
            else if(l || r || mi) mf+=1;
        }

        return mf;
    }
};