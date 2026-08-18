class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);

        // Check every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            // Each number is counted once for this subarray
            for (int x : seen) {
                count[x]++;
            }
        }

        // Find the largest number appearing in exactly one subarray
        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};