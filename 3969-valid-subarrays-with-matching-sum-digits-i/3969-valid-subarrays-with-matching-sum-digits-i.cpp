class Solution {
public:
    bool isValid(long long sum, int x) {
        int lastDigit = sum % 10;

        while (sum >= 10)
            sum /= 10;

        int firstDigit = sum;

        return firstDigit == x && lastDigit == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;

            for (int j = i; j < n; j++) {
                sum += nums[j];

                if (isValid(sum, x))
                    ans++;
            }
        }

        return ans;
    }
};