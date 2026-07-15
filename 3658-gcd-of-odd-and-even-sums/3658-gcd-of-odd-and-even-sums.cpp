class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;
        int currentOdd = 1, currentEven = 2;

        for (int i = 0; i < n; i++) {
            oddSum += currentOdd;
            evenSum += currentEven;

            currentOdd += 2;
            currentEven += 2;
        }

        return gcd(oddSum, evenSum);
    }
};