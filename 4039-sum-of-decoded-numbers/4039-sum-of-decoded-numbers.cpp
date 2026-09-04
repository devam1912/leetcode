class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long MOD = 1000000007;
        long long ans = 0;

        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;
            int digits = 0;
            long long temp = d;

            while (temp > 0) {
                digits++;
                temp /= 10;
            }

            int yDigits = digits - width;
            long long p = 1;

            for (int i = 0; i < yDigits; i++) {
                p = p * 10;
            }

            long long x = d / p;
            long long y = d % p;

            long long value = 1;

            while (y > 0) {
                if (y % 2 == 1) {
                    value = (value * x) % MOD;
                }

                x = (x * x) % MOD;
                y = y / 2;
            }

            ans = (ans + value) % MOD;
        }

        return ans;
    }
};