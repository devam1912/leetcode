class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(vector<int>& nums, int start) {

        if (path.size() >= 2) {
            ans.push_back(path);
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (used.count(nums[i]))
                continue;

            // Must remain non-decreasing
            if (!path.empty() && nums[i] < path.back())
                continue;

            used.insert(nums[i]);

            path.push_back(nums[i]);      // choose

            backtrack(nums, i + 1);       // explore

            path.pop_back();              // unchoose
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};