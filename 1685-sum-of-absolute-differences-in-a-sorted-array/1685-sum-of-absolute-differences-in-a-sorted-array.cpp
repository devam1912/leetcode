class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0;

        for (int i = 0; i < n; i++) {
            long long rightSum = total - leftSum - nums[i];

            long long leftPart =
                1LL * nums[i] * i - leftSum;

            long long rightPart =
                rightSum - 1LL * nums[i] * (n - i - 1);

            ans[i] = leftPart + rightPart;

            leftSum += nums[i];
        }

        return ans;
    }
};