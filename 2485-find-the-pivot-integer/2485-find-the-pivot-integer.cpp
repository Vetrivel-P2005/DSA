class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = (n * (n + 1)) / 2;
        int leftSum = 0;

        for (int pivot = 1; pivot <= n; pivot++) {
            leftSum += pivot;
            int rightSum = totalSum - leftSum + pivot;

            if (leftSum == rightSum) {
                return pivot; 
            }
        }

        return -1;
    }
};