class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        int i = 0;

        while (i < n) {

            // Only valid numbers [1...n] have a correct position
            if (nums[i] >= 1 && nums[i] <= n) {

                int correct = nums[i] - 1;

                // Swap only if it's not already at its correct position
                if (nums[i] != nums[correct]) {
                    swap(nums[i], nums[correct]);
                    continue;   // Stay on the same index
                }
            }

            // Invalid number OR already in correct place
            i++;
        }

        // Find first index where number is incorrect
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        // If every number is in place
        return n + 1;
    }
};