class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if(n < 2) {
            return 0;
        }

        int max_diff = INT_MIN;

        sort(nums.begin(), nums.begin() + n);

        for(int i = 0; i < n - 1; i++) {

            int maximum = nums[i + 1] - nums[i];

            max_diff = max(max_diff, maximum);
        }

        return max_diff;
    }
};