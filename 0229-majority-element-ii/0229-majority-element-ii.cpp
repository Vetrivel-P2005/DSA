class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1 = 0, ct2 = 0;
        long el1 = LONG_MIN;
        long el2 = LONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(ct1==0 && el1!=nums[i]){
                ct1 = 1;
                el1 = nums[i];
            }
            else if(ct2==0 && el2!=nums[i]){
                ct2 = 1;
                el2 = nums[i];
            }
            else if(nums[i]==el1)ct1++;
            else if(nums[i]==el2)ct2++;
            else{
                ct1--;
                ct2--;
            }
        }
        vector<int> ls;
        ct1 = 0,ct2 = 0;
        for(int i=0;i<nums.size();i++){
            if(el1 == nums[i]) ct1++;
            else if(el2 == nums[i]) ct2++;
        }
        int m = (int)(nums.size()/3) + 1;
        if(ct1 >= m) ls.push_back(el1);
        if(ct2 >= m) ls.push_back(el2);
        sort(ls.begin(),ls.end());
        return ls;
    }
};