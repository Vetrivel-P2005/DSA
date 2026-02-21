class Solution {
public:
    bool isHappy(int n) {
        set<int> used;
        while(true){
            int sum = 0;
            while(n!=0){
                int digit = n % 10;
                sum += digit * digit;
                n=n/10;
            }
            if(sum==1) return true;
            n=sum;

            if(used.find(n)!= used.end()){
                return false;
            }
            used.insert(n);
        
        }
    }
};