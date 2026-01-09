class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;

        int longest = 1;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }

        for(auto it : nums){
            if(s.find(it-1)==s.end()){
                int ct = 1;
                int x = it;
                while(s.find(x+1)!=s.end()){
                    x=x+1;
                    ct=ct+1;
                }
                longest = max(longest,ct);
            }
        }
        return longest;
    }
};