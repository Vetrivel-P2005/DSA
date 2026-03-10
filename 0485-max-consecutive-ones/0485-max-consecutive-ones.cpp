class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int o=0,n=0;
        for(const auto& c:nums){
            if(c==1){
                o++;
                n = max(n, o);
            }
            else
                o=0;
        }
        return n;
    }
};