class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 0;
        int x;

        for(int i=0;i<nums.size();i++){
            if(ct==0){
                ct=1;
                x=nums[i];
            }
            else if(x==nums[i]){
                ct++;
            }
            else{
                ct--;
            }
        }
        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                c++;
            }
        }
        if(c>(nums.size()/2)){
            return x;
        }
        return -1;
    }
};