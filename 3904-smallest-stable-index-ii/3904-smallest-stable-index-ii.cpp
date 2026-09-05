class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefMax;
        int currMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);
            prefMax.push_back(currMax);
        }

        vector<int> suffMin(n);
        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            currMin = min(currMin, nums[i]);
            suffMin[i] = currMin;
        }

        for (int i = 0; i < n; i++) {
            if (prefMax[i] - suffMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};