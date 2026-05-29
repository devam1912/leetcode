class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;

        int n = nums.size();
        sort(nums.begin(), nums.end());
            // as subsequences are needed so for that we calulate 2's power vector for 2's power choices
        vector<int> power(n);
        power[0] = 1;
        for (int k = 1; k < n; k++) {
            power[k] = (2LL * power[k - 1]) % MOD;
        }

        int i = 0;
        int j = n - 1;
        long long ans = 0;

        while (i <= j) {
            int sum = nums[i] + nums[j];

            if (sum > target) {
                j--;
            } else {
                ans = (ans + power[j - i]) % MOD;
                i++;
            }
        }

        return (int)ans;
    }
};