class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int prefix_sum = 0;
        int ct = 0;

        mp[0]=1;
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            int r = prefix_sum - k;

            if(mp.find(r)!=mp.end()){
                ct+= mp[r];
            }

            mp[prefix_sum]++;
        }

        return ct;
    }
};