class Solution {
public:
    string addBinary(string a, string b) {
        string res ="";
        int i = a.length()-1,j=b.length()-1;
        int car = 0;
        while(i>=0 || j>=0){
            int sum = car;
            if(i>=0) sum+=a[i--] - '0';
            if(j>=0) sum+=b[j--] - '0';
            res += (sum % 2) + '0';
            car = sum / 2;
        }
        if(car)res+=to_string(car);
        reverse(res.begin(),res.end());
        return res;
    }
};