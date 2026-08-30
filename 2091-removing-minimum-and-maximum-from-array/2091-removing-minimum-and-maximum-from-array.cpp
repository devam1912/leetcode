class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int minind = -1;
        int maxind = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == mini)
                minind = i;
            else if (nums[i] == maxi)
                maxind = i;
        }

        int bothFront = max(minind, maxind) + 1;

        int bothBack = n - min(minind, maxind);

        // Remove one from front and one from back
        int oneEach = min(minind + 1 + (n - maxind), maxind + 1 + (n - minind));

        return min({bothFront, bothBack, oneEach});
    }
};